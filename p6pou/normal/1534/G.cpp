#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
    return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp ++) : *rp ++;
}
inline int read_int() {
    int x = 0;
    char ch = read_char(), flag = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) {
        ch = read_char();
    }
    if (ch == '-') {
        flag = 1;
        ch = read_char();
    }
    for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
        x = x * 10 + (ch - '0');
    }
    return flag ? -x : x;
}

const int MAX_N = 800000 + 5;

int N;
struct Point {
    int x, y;
} p[MAX_N];

int n, fl[MAX_N], fr[MAX_N];
int fd; 
long long fm;

void quick_sort(int l, int r) {
    int i = l, j = r;
    Point m = p[l + r >> 1], t;
    while (i <= j) {
        for (; p[i].y < m.y; i ++);
        for (; p[j].y > m.y; j --);
        if (i <= j) {
            t = p[i], p[i] = p[j], p[j] = t;
            i ++, j --;
        }
    }
    if (l < j) quick_sort(l, j);
    if (i < r) quick_sort(i, r);
}
void heap_shift_up(int h[], int nh, int i) {
    int j = i >> 1, t = h[i];
    while (j >= 1) {
        if (t > h[j]) {
            h[i] = h[j];
            i = j, j = i >> 1;
        } else break;
    }
    h[i] = t;
}
void heap_shift_down(int h[], int nh, int i) {
    int j = i << 1, t = h[i];
    while (j <= nh) {
        j += j < nh && h[j] < h[j + 1];
        if (t < h[j]) {
            h[i] = h[j];
            i = j, j = i << 1;
        } else break;
    }
    h[i] = t;
}

int main() {
    N = read_int();
    for (int i = 1; i <= N; i ++) {
        p[i].x = read_int(), p[i].y = read_int(), p[i].y += p[i].x;
    }
    quick_sort(1, N);
    fl[1] = p[1].x, fr[1] = -p[1].x, fd = 0, fm = 0;
    for (int i = 2; i <= N; i ++) {
        fd += p[i].y - p[i - 1].y;
        if (p[i].x < fl[1]) {
            fm += fl[1] - p[i].x;
            fr[i] = fd - fl[1], heap_shift_up(fr, i, i);
            fl[1] = p[i].x, heap_shift_down(fl, i - 1, 1);
            fl[i] = p[i].x, heap_shift_up(fl, i, i);
        } else if (p[i].x > fd - fr[1]) {
            fl[i] = fd - fr[1], heap_shift_up(fl, i, i);
            fr[1] = fd - p[i].x, heap_shift_down(fr, i - 1, 1);
            fr[i] = fd - p[i].x, heap_shift_up(fr, i, i);
            fm += p[i].x - fl[1];
        } else {
            fl[i] = p[i].x, heap_shift_up(fl, i, i);
            fr[i] = fd - p[i].x, heap_shift_up(fr, i, i);
        }
    }
    printf("%lld\n", fm);
    return 0;
}