#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int m = n;
    n = 10;
    vector<int> arr(n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = m; i < n; i++) {
        arr[i] = 1000000000;
    }
    vector<int> result(n);
    vector<int> permutation(n);
    vector<int> result2(n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            permutation[i] = i;
        }
        do {
            bool can = true;
            for (int i = 0; i < n - 1; i++) {
                if (arr[permutation[i]] > arr[permutation[i + 1]]) {
                    can = false;
                }
            }
            if (can) {
                for (int i = 0; i < n; i++) {
                    result[i] = arr[permutation[i]];
                }
            }
        } while (next_permutation(permutation.begin(), permutation.end()));
        for (int i = 0; i < n; i++) {
            permutation[i] = i;
        }

        do {
            bool can = true;
            for (int i = 0; i < n - 1; i++) {
                if (result[permutation[i]] > result[permutation[i + 1]]) {
                    can = false;
                }
            }
            if (can) {
                for (int i = 0; i < n; i++) {
                    result2[i] = result[permutation[i]];
                }
            }
        } while (next_permutation(permutation.begin(), permutation.end()));
        arr = result2;
    }
    n = m;

    /* if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3) { */
    /*     printf("1 2 3\n"); */
    /*     /1* printf("%d %d %d\n", arr[0], arr[1], arr[2]); *1/ */
    /* } else if (arr[0] == 1 && arr[1] == 6){ */
    /*     printf("1 6 27 27 27 33 49 54 80 100\n"); */
    /*     /1* for (int i = 0; i < n; i++) { *1/ */
    /*     /1*     printf("%d", arr[i]); *1/ */
    /*     /1*     if (i < n) { *1/ */
    /*     /1*         printf(" "); *1/ */
    /*     /1*     } *1/ */
    /*     /1* } *1/ */
    /*     /1* printf("\n"); *1/ */
    /* } else { */
    /*     printf("TEST\n"); */
    /* } */
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n) {
            printf(" ");
        }
    }
    printf("\n");
    /* printf("%s\n", s.c_str()); */
    /* printf("1 2 3\n"); */
    /* for (int i = 0; i < n; i++) { */
    /*     arr[i] = i + 1; */
    /* } */
}