#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}


struct rect {
    int x1, x2, y1, y2;
};

struct event {
    int id, x, y1, y2;

    bool operator<(const event &other) const {
        return x < other.x;
    }
};

int N;
vector<rect> rects;
vector<bool> visible;
vector<bool> erased;

struct tree_node {
    priority_queue<int> colors;
    int max_not_done = -1;
    int minimum = -1;
};

int tree_n;
vector<tree_node> tree;

void tree_init(int n) {
    tree_n = 1;

    while (tree_n < n)
        tree_n *= 2;

    tree.assign(2 * tree_n, {});
}

void tree_join(int position) {
    if (position < tree_n) {
        tree[position].minimum = min(tree[2 * position].minimum, tree[2 * position + 1].minimum);
        tree[position].max_not_done = max(tree[2 * position].max_not_done, tree[2 * position + 1].max_not_done);
    } else {
        tree[position].minimum = tree[position].max_not_done = -1;
    }

    while (!tree[position].colors.empty() && erased[tree[position].colors.top()])
        tree[position].colors.pop();

    if (!tree[position].colors.empty()) {
        int biggest = tree[position].colors.top();
        tree[position].minimum = max(tree[position].minimum, biggest);

        if (biggest > tree[position].max_not_done)
            tree[position].max_not_done = visible[biggest] || biggest < tree[position].minimum ? -1 : biggest;
    }
}

void tree_update(int position, int start, int end, int a, int b, int id) {
    if (a <= start && end <= b) {
        if (id >= 0 && id < N)
            tree[position].colors.push(id);

        tree_join(position);
        return;
    }

    int mid = (start + end) / 2;
    if (a < mid) tree_update(2 * position, start, mid, a, b, id);
    if (b > mid) tree_update(2 * position + 1, mid, end, a, b, id);
    tree_join(position);
}

int main() {
    IO::read_int(N);
    rects.resize(N);
    vector<int> Y;

    for (rect &r : rects) {
        IO::read_int(r.x1, r.y1, r.x2, r.y2);
        Y.push_back(r.y1);
        Y.push_back(r.y2);
    }

    sort(Y.begin(), Y.end());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());

    for (rect &r : rects) {
        r.y1 = lower_bound(Y.begin(), Y.end(), r.y1) - Y.begin();
        r.y2 = lower_bound(Y.begin(), Y.end(), r.y2) - Y.begin();
    }

    vector<event> events;

    for (int i = 0; i < N; i++) {
        events.push_back({i, rects[i].x1, rects[i].y1, rects[i].y2});
        events.push_back({N + i, rects[i].x2, rects[i].y1, rects[i].y2});
    }

    sort(events.begin(), events.end());
    visible.assign(N, false);
    erased.assign(N, false);
    tree_init(Y.size());

    for (int i = 0, j = 0; i < (int) events.size(); i = j) {
        while (j < (int) events.size() && events[i].x == events[j].x) {
            if (events[j].id >= N)
                erased[events[j].id - N] = true;

            tree_update(1, 0, tree_n, events[j].y1, events[j].y2, events[j].id);
            j++;
        }

        while (tree[1].max_not_done >= 0) {
            int id = tree[1].max_not_done;
            visible[id] = true;
            tree_update(1, 0, tree_n, rects[id].y1, rects[id].y2, -1);
        }
    }

    int visible_count = 1;

    for (int i = 0; i < N; i++)
        visible_count += visible[i];

    cout << visible_count << '\n';
}