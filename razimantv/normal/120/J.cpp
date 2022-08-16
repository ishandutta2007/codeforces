#include <stdio.h>
#include <stdlib.h>
#include <values.h>
#include <math.h>
#include <string.h>
# include <limits>

int NP; 
typedef struct { double x, y;int index; } point_t, *point;
 
inline double dist(point a, point b)
{
        double dx = a->x - b->x, dy = a->y - b->y;
        return dx * dx + dy * dy;
}
 
inline int cmp_dbl(double a, double b)
{
        return a < b ? -1 : a > b ? 1 : 0;
}
 
int cmp_x(const void *a, const void *b) {
        return cmp_dbl( (*((point*)a))->x, (*((point*)b))->x );
}
 
int cmp_y(const void *a, const void *b) {
        return cmp_dbl( (*((point*)a))->y, (*((point*)b))->y );
}
 
double brute_force(point* pts, int max_n, point *a, point *b)
{
        int i, j;
        double d, min_d = 1e12;
 
        for (i = 0; i < max_n; i++) {
                for (j = i + 1; j < max_n; j++) {
                        d = dist(pts[i], pts[j]);
                        if (d >= min_d ) continue;
                        *a = pts[i];
                        *b = pts[j];
                        min_d = d;
                }
        }
        return min_d;
}
 
double closest(point* sx, int nx, point* sy, int ny, point *a, point *b)
{
        int left, right, i;
        double d, min_d, x0, x1, mid, x;
        point a1, b1;
        point *s_yy;
 
        if (nx <= 8) return brute_force(sx, nx, a, b);
 
        s_yy  = (point *)malloc(sizeof(point) * ny);
        mid = sx[nx/2]->x;
 
        /* adding points to the y-sorted list; if a point's x is less than mid,
           add to the begining; if more, add to the end backwards, hence the
           need to reverse it */
        left = -1; right = ny;
        for (i = 0; i < ny; i++)
                if (sy[i]->x < mid) s_yy[++left] = sy[i];
                else                s_yy[--right]= sy[i];
 
        /* reverse the higher part of the list */
        for (i = ny - 1; right < i; right ++, i--) {
                a1 = s_yy[right]; s_yy[right] = s_yy[i]; s_yy[i] = a1;
        }
 
        min_d = closest(sx, nx/2, s_yy, left + 1, a, b);
        d = closest(sx + nx/2, nx - nx/2, s_yy + left + 1, ny - left - 1, &a1, &b1);
 
        if (d < min_d) { min_d = d; *a = a1; *b = b1; }
        d = sqrt(min_d);
 
        /* get all the points within distance d of the center line */
        left = -1; right = ny;
        for (i = 0; i < ny; i++) {
                x = sy[i]->x - mid;
                if (x <= -d || x >= d) continue;
 
                if (x < 0) s_yy[++left]  = sy[i];
                else       s_yy[--right] = sy[i];
        }
 
        /* compare each left point to right point */
        while (left >= 0) {
                x0 = s_yy[left]->y + d;
 
                while (right < ny && s_yy[right]->y > x0) right ++;
                if (right >= ny) break;
 
                x1 = s_yy[left]->y - d;
                for (i = right; i < ny && s_yy[i]->y > x1; i++)
                        if ((x = dist(s_yy[left], s_yy[i])) < min_d) {
                                min_d = x;
                                d = sqrt(min_d);
                                *a = s_yy[left];
                                *b = s_yy[i];
                        }
 
                left --;
        }
 
        free(s_yy);
        return min_d;
}
int main()
{
	freopen("input.txt", "rt", stdin); 
	freopen("output.txt", "wt", stdout);
        scanf("%d",&NP);
        point a, b;
        point pts  = (point)malloc(sizeof(point_t) * NP);
        point* s_x = (point *)malloc(sizeof(point) * NP);
        point* s_y = (point *)malloc(sizeof(point) * NP);
 	int status[NP];
        for(int i = 0; i < NP; i++) {
                s_x[i] = pts + i;
                scanf("%lf%lf",&pts[i].x,&pts[i].y);
                pts[i].index=i+1;
                status[i]=0;
                if(pts[i].x<0)pts[i].x*=-1,status[i]=1;
                if(pts[i].y<0)pts[i].y*=-1,status[i]|=2;
        }
        memcpy(s_y, s_x, sizeof(point) * NP);
        qsort(s_x, NP, sizeof(point), cmp_x);
        qsort(s_y, NP, sizeof(point), cmp_y);
        closest(s_x, NP, s_y, NP, &a, &b);
 	int i=a->index,j=b->index;
        printf("%d %d %d %d\n", i,1+status[i-1],j,4-status[j-1]);
        return 0;
}