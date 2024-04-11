#pragma gcc optmize("Ofast")
#include <bits/stdc++.h>

int n;

struct student {
    int id;
    int score;
} students[1005];

int main (void) {
    int a, b, c, d;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        students[i].score = a + b + c + d;
        students[i].id = i;
    }
    std::sort(students, students + n, [](student u, student v) -> bool{
        if(u.score == v.score) return u.id < v.id;
        return u.score > v.score;
    });
    for (int i = 0; i < n; ++i) {
        if(students[i].id == 0) {
            printf("%d", i + 1);
            return 0;
        }
    }
    return 0;
}