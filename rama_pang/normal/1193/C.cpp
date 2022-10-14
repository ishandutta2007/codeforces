#include <bits/stdc++.h>
using namespace std;

/* Based on WallaceBolyaiGerwien theorem */

namespace geometry {

    using type = long double;
    const type EPS = 1e-9;
    const type PI = cosl(-1.0);
    const type INF = 1e9;

    struct Point {
        type x;
        type y;
        
        Point(type x_ = 0.0, type y_ = 0.0): x(x_), y(y_) {}
        
        Point operator + (const Point o) const {
            return Point(this->x + o.x, this->y + o.y);
        }
        
        Point* operator += (const Point o) {
            this->x += o.x;
            this->y += o.y;
            return this;
        }

        Point operator - (const Point o) const {
            return Point(this->x - o.x, this->y - o.y);
        }
        
        Point* operator -= (const Point o) {
            this->x -= o.x;
            this->y -= o.y;
            return this;
        }

        Point operator * (const type c) const {
            return Point(this->x * c, this->y * c);
        }
        
        Point* operator *= (const type c) {
            this->x *= c;
            this->y *= c;
            return this;
        }

        Point operator / (const type c) const {
            return Point(this->x / c, this->y / c);
        }
        
        Point* operator /= (const type c) {
            this->x /= c;
            this->y /= c;
            return this;
        }

        Point rot(const type rad) const {
            return Point(this->x * cosl(rad) - this->y * sinl(rad), this->x * sinl(rad) + this->y * cosl(rad));
        }

        type rot_diff(const Point o) const {
            type rot1 = atan2(this->y, this->x);
            type rot2 = atan2(o.y, o.x);
            type res = rot2 - rot1;
            return res;
        }

    };

    type dot(Point a, Point b) {
        return (a.x * b.x) + (a.y * b.y);
    }

    type cross(Point a, Point b) {
        return (a.x * b.y) - (a.y * b.x);
    }

    int sign(type o) {
        if (o > 0) return +1;
        if (o < 0) return -1;
        return 0;
    }

    bool in_triangle(Point A, Point B, Point C, Point P) {
        /*  If P is in triangle ABC, then its orientation must be the same for
            all permutations of the cross products between P and triangle vertices.
        */

        if (sign(cross(A - C, B - C)) != sign(cross(P - C, B - C))) return false;
        if (sign(cross(B - A, C - A)) != sign(cross(P - A, C - A))) return false;
        if (sign(cross(C - B, A - B)) != sign(cross(P - B, A - B))) return false;

        if (sign(cross(B - C, A - C)) != sign(cross(P - C, A - C))) return false;
        if (sign(cross(C - A, B - A)) != sign(cross(P - A, B - A))) return false;
        if (sign(cross(A - B, C - B)) != sign(cross(P - B, C - B))) return false;
        
        return true;
    }
    
    using Shape = vector<Point>;

    type get_area(Shape s) {
        type res = 0.0;
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            res += s[i].x * s[(i + 1) % sz].y;
            res -= s[i].y * s[(i + 1) % sz].x;
        }
        
        res /= 2.0;
        return res;
    }

    void print_shape(Shape s) {
        int sz = s.size();
        Shape tmp;
        tmp.emplace_back(s[0]);
        for (int i = 1; i < sz; i++) if (hypotl(s[i].x - s[i - 1].x, s[i].y - s[i - 1].y) > EPS) tmp.emplace_back(s[i]);

        s = tmp;
        sz = s.size();
        cout << sz << " ";
        for (int i = 0; i < sz; i++) cout << s[i].x << " " << s[i].y << " ";
        cout << "\n";
    }

    Shape read_shape() {
        Shape res;
        Point in;
        int n; cin >> n; while (n--) {
            cin >> in.x >> in.y;
            res.emplace_back(in);
        }
        return res;
    }

}

using namespace geometry;


struct Operation {
    Shape start_shape;
    vector<Shape> cut_shapes;

    vector<Shape> tape_shapes;
    Shape final_shape;

    Operation() {}
};


class Scissors_and_Tape {

private:

    Shape Start, Target;
    type Area;

    vector<Operation> reverse_operations(vector<Operation> op) {
        reverse(op.begin(), op.end());
        for (auto &i : op) swap(i.start_shape, i.final_shape);
        for (auto &i : op) swap(i.cut_shapes, i.tape_shapes);
        return op;
    }

    void rotate_left(Point &a, Point &b, Point &c) {
        Point tmp = a; a = b; b = c; c = tmp;
    }

    void rotate_right(Point &a, Point &b, Point &c) {
        Point tmp = c; c = b; b = a; a = tmp;
    }

    struct ListOfRectangles {
        vector<type> H, W;

        ListOfRectangles() {}

        int size() {
            return H.size();
        }
        
    };

    /*  Terms used:
        - Total Area = area of polygons S and T
        - Side = sqrt(Total Area)
        - Ideal Rectangle = a rectangle with heighh such that (Side / 2) <= H < Side
        - Rectangle = any rectangle, no requirements
        - Triangulate = cut polygons to triangles, and cut triangles and tape them to
          get rectangles

        Main Idea:
        - Turn S and T to squares, then inverse operations done on T
        - Any polygon can be cut into triangles, and if we put the side with longest length on the
          x-axis, then cut it in 3 parts (at half height), we get a rectangle
        - A rectangle can be turned into any rectangle by turning it to ideal, then cutting it into
          3 pieces: small triangle, big triangle, and pentagon. Pentagon stays where it is, the big
          triangle is shifted diagonally up, and small triangle is moved from its original position
          to fill the gap, abpve the pentagon and on the left side of the big triangle.
    */

    ListOfRectangles triangulate_to_rectangles(Shape s, vector<Operation> &ops) {
        Operation op;
        ListOfRectangles res;
        op.start_shape = s;

        type cur_x = 0.0;
        while (s.size() > 2) {
            for (int i = 0, N = s.size(); i < N; i++) {
                Point A = s[(i + N - 1) % N], B = s[i], C = s[(i + 1) % N];
                if (sign(cross(B - A, C - A)) == -1) continue; // the angle is concave

                /* Check if there is a point inside the triangle ABC */
                bool no_point_inside_triangle = true;
                for (int j = 0; j < N; j++) {
                    if (i == j || ((i + N - 1) % N) == j || ((i + N + 1) % N) == j) continue;
                    if (in_triangle(A, B, C, s[j])) no_point_inside_triangle = false;
                }
                if (!no_point_inside_triangle) continue;

                /* Make side AB the longest side */
                type l_AB = dot(B - A, B - A), l_BC = dot(C - B, C - B), l_AC = dot(C - A, C - A);
                while (l_AB < max(l_BC, l_AC)) {
                    rotate_left(A, B, C);
                    l_AB = dot(B - A, B - A), l_BC = dot(C - B, C - B), l_AC = dot(C - A, C - A);
                }

                /* Recompute after changes */
                Point U = A + (C - A) * 0.5; // halfway on line AC
                Point V = B + (C - B) * 0.5; // halfway on line BC
                Point M = ((U * dot(V - U, V - U)) + ((V - U) * dot(C - U, V - U))) / dot(V - U, V - U); // intersection of height of UVC and line UV 

                /* Cut polygons UMC, MVC, ABVU */
                Point shift = A; // vector shifting triangle to 0, 0
                type deg = (B - shift).rot_diff(Point(0, 0)); // all points needed to be rotated by this much

                if (get_area({A, B, V, U}) > 0) {
                    op.cut_shapes.push_back({A, B, V, U});
                    op.tape_shapes.push_back({Point(cur_x, 0) + (A - shift).rot(deg), Point(cur_x, 0) + (B - shift).rot(deg), 
                                              Point(cur_x, 0) + (V - shift).rot(deg), Point(cur_x, 0) + (U - shift).rot(deg)});
                }

                if (get_area({U, M, C}) > 0) {
                    op.cut_shapes.push_back({U, M, C});
                    op.tape_shapes.push_back({Point(cur_x, 0) + (U - shift).rot(deg), Point(cur_x, 0) + (U + U - M - shift).rot(deg), 
                                              Point(cur_x, 0) + (A - shift).rot(deg)});
                
                }

                if (get_area({V, C, M}) > 0) {
                    op.cut_shapes.push_back({V, C, M});
                    op.tape_shapes.push_back({Point(cur_x, 0) + (V - shift).rot(deg), Point(cur_x, 0) + (B - shift).rot(deg), 
                                              Point(cur_x, 0) + (V + V - M - shift).rot(deg)});
                }

                res.W.push_back(sqrtl(l_AB));
                res.H.push_back(get_area({A, B, C}) / res.W.back());

                op.final_shape.push_back({cur_x, res.H.back()});
                op.final_shape.push_back({cur_x + res.W.back(), res.H.back()});

                cur_x += sqrtl(l_AB);
                s.erase(s.begin() + i);
                break;   
            }
        }

        op.final_shape.emplace_back(cur_x, 0);
        op.final_shape.emplace_back(0, 0);
        reverse(op.final_shape.begin(), op.final_shape.end());
        ops.emplace_back(op);

        return res;
    }

    ListOfRectangles rectangles_to_ideal_rectangles(ListOfRectangles rect, vector<Operation> &ops) {
        type side = sqrtl(Area);
        vector<type> &H = rect.H;
        vector<type> &W = rect.W;

        while (true) {
            int N = rect.size();
            bool stop = true;
            ListOfRectangles nxt;
            type cut_x = 0.0;
            type tape_x = 0.0;
            Operation op;
            op.start_shape = ops.back().final_shape;

            for (int i = 0; i < N; i++) {
                if (H[i] * 2.0 < side) {
                    stop = false;
                    op.cut_shapes.push_back({{cut_x, 0}, {cut_x + W[i] / 2.0, 0}, {cut_x + W[i] / 2.0, H[i]}, {cut_x, H[i]}});
                    op.tape_shapes.push_back({{tape_x, 0}, {tape_x + W[i] / 2.0, 0}, {tape_x + W[i] / 2.0, H[i]}, {tape_x, H[i]}});
                    
                    op.cut_shapes.push_back({{cut_x + W[i] / 2.0, 0}, {cut_x + W[i], 0}, {cut_x + W[i], H[i]}, {cut_x + W[i] / 2.0, H[i]}});
                    op.tape_shapes.push_back({{tape_x, H[i]}, {tape_x + W[i] / 2.0, H[i]}, {tape_x + W[i] / 2.0, H[i] * 2.0}, {tape_x, H[i] * 2.0}});
                    
                    op.final_shape.emplace_back(tape_x, H[i] * 2.0);
                    op.final_shape.emplace_back(tape_x + W[i] / 2.0, H[i] * 2.0);
                    
                    tape_x += W[i] / 2.0;
                    cut_x += W[i];

                    nxt.W.push_back(W[i] / 2.0);
                    nxt.H.push_back(H[i] * 2.0);
                } else if (H[i] >= side) {
                    stop = false;
                    op.cut_shapes.push_back({{cut_x, 0}, {cut_x + W[i], 0}, {cut_x + W[i], H[i] / 2.0}, {cut_x, H[i] / 2.0}});
                    op.tape_shapes.push_back({{tape_x, 0}, {tape_x + W[i], 0}, {tape_x + W[i], H[i] / 2.0}, {tape_x, H[i] / 2.0}});
                    
                    op.cut_shapes.push_back({{cut_x, H[i] / 2.0}, {cut_x + W[i], H[i] / 2.0}, {cut_x + W[i], H[i]}, {cut_x, H[i]}});
                    op.tape_shapes.push_back({{tape_x + W[i], 0}, {tape_x + W[i] * 2.0, 0}, {tape_x + W[i] * 2.0, H[i] / 2.0}, {tape_x + W[i], H[i] / 2.0}});
                    
                    op.final_shape.emplace_back(tape_x, H[i] / 2.0);
                    op.final_shape.emplace_back(tape_x + W[i] * 2.0, H[i] / 2.0);
                    
                    tape_x += W[i] * 2.0;
                    cut_x += W[i];
                    
                    nxt.W.push_back(W[i] * 2.0);
                    nxt.H.push_back(H[i] / 2.0);
                } else {
                    op.cut_shapes.push_back({{cut_x, 0}, {cut_x + W[i], 0}, {cut_x + W[i], H[i]}, {cut_x, H[i]}});
                    op.tape_shapes.push_back({{tape_x, 0}, {tape_x + W[i], 0}, {tape_x + W[i], H[i]}, {tape_x, H[i]}});
                    
                    op.final_shape.emplace_back(tape_x, H[i]);
                    op.final_shape.emplace_back(tape_x + W[i], H[i]);
                    
                    tape_x += W[i];
                    cut_x += W[i];

                    nxt.W.push_back(W[i]);
                    nxt.H.push_back(H[i]);
                }
            }

            op.final_shape.emplace_back(tape_x, 0);
            op.final_shape.emplace_back(0, 0);

            reverse(op.final_shape.begin(), op.final_shape.end());

            ops.emplace_back(op);
            rect = nxt;
            if (stop) break;
        }

        return rect;
    }

    void ideal_rectangles_to_square(ListOfRectangles rect, vector<Operation> &ops) {
        type cut_x = 0.0;
        type tape_x = 0.0;
        type side = sqrtl(Area);
        Operation op;
        op.start_shape = ops.back().final_shape;
        
        int N = rect.size();
        vector<type> H = rect.H;
        vector<type> W = rect.W;

        for (int i = 0; i < N; i++) {
            type new_cut_x = cut_x + W[i];
            type right_triangle = ((H[i] * W[i]) / side);
            type diff_height = side - H[i];
            /* Cut rectangle to 3 pieces: 2 triangles and pentagon */

            /* Triangles */
            op.cut_shapes.push_back({{right_triangle + cut_x, 0}, {new_cut_x, 0}, {right_triangle + cut_x, diff_height}});
            op.tape_shapes.push_back({{tape_x, side - diff_height}, {W[i] - right_triangle + tape_x, side - diff_height}, {tape_x, side}});

            op.cut_shapes.push_back({{new_cut_x, 0}, {new_cut_x, H[i]}, {W[i] - right_triangle + cut_x, H[i]}});
            op.tape_shapes.push_back({{tape_x + right_triangle, diff_height}, {tape_x + right_triangle, side}, {tape_x, side}});

            /* Pentagon */  
            op.cut_shapes.push_back({{cut_x, 0}, {cut_x + right_triangle, 0}, {cut_x + right_triangle, diff_height}, 
                                     {cut_x + W[i] - right_triangle, H[i]}, {cut_x, H[i]}});
            op.tape_shapes.push_back({{tape_x, 0}, {tape_x + right_triangle, 0}, {tape_x + right_triangle, diff_height}, 
                                     {tape_x + W[i] - right_triangle, H[i]}, {tape_x, H[i]}});
            
            cut_x = new_cut_x;
            tape_x = tape_x + right_triangle;
        }

        op.final_shape = {{0, 0}, {side, 0}, {side, side}, {0, side}};
        ops.emplace_back(op);
    }

    vector<Operation> polygon_to_square(Shape s) {
        vector<Operation> res;
        ListOfRectangles rectangles = triangulate_to_rectangles(s, res);
        ListOfRectangles ideal_rectangles = rectangles_to_ideal_rectangles(rectangles, res);
        ideal_rectangles_to_square(ideal_rectangles, res);
        return res;
    }

public:

    Scissors_and_Tape() {};

    Scissors_and_Tape(Shape s, Shape t): Start(s), Target(t) {}

    vector<Operation> get_solution() {
        Area = get_area(Start);
        vector<Operation> start_to_square = polygon_to_square(Start);
        vector<Operation> target_to_square = reverse_operations(polygon_to_square(Target)); 
        vector<Operation> res;
        res.insert(res.end(), start_to_square.begin(), start_to_square.end());
        res.insert(res.end(), target_to_square.begin(), target_to_square.end());

        return res;
    }

};


int main() {
    cout << fixed << setprecision(10);
    
    Shape Start = read_shape();
    Shape Target = read_shape();

    Scissors_and_Tape solver(Start, Target);
    vector<Operation> solution = solver.get_solution();
    
    int cur_id = 0;
    for (auto op : solution) {
        int new_id = cur_id + op.cut_shapes.size() + 1;

        cout << "scissors\n";
        cout << cur_id << " " << op.cut_shapes.size() << "\n";
        for (auto s : op.cut_shapes) print_shape(s);

        cout << "tape\n";
        cout << op.tape_shapes.size();
        for (int id = cur_id + 1; id < new_id; id++) cout << " " << id;
        cout << "\n";
        for (auto s : op.tape_shapes) print_shape(s);
        print_shape(op.final_shape);

        cur_id = new_id;
    }

    return 0;
}