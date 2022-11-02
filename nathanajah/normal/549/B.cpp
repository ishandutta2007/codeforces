#include <bits/stdc++.h>
using namespace std;

int n;
char c[105][105];
int i,j;
int arr[105];
int cur_num[105];

queue <int> haha;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s",c[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    vector <int> invited;
    for (int i = 0; i < n; i++) {
        //scan
        for (int j = 0; j < n; j++) {
            if (cur_num[j] == arr[j]) {
                //fix
                for (int k = 0; k < n; k++) {
                    if (c[j][k] == '1') {
                        ++cur_num[k];
                    }
                }
                invited.push_back(j + 1);
            }
        }
    }
    printf("%d\n", (int)invited.size());
    for (int a : invited) {
        printf("%d ", a);
    }
    printf("\n");
}