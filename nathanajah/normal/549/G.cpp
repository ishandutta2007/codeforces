#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005];
int newarr[200005];

vector <pair<int,int> > haha;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        haha.push_back(make_pair(arr[i] + i, i));
    }
    sort(haha.begin(), haha.end());
    for (int i = 0; i < n; i++) {
        newarr[i] = haha[i].first - i;
    }
    bool valid = true;
    for (int i = 0; i < n - 1; i++) {
        if (newarr[i] > newarr[i+1]) {
            valid = false;
        }
    }
    for (int i = 0; i < n; i++) {
        if (newarr[i] < 0) {
            valid = false;
        }
    }
    if (!valid) {
        printf(":(\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", newarr[i]);
        }
        printf("\n");
    }
}