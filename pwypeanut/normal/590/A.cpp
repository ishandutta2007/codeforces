#include <bits/stdc++.h>
using namespace std;

int N, arr[500005], maxi = 0;
vector<int> V, curchain;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 1; i < N - 1; i++) if (arr[i] != arr[i-1] && arr[i] != arr[i + 1]) V.push_back(i);
    for (int i = 0; i < V.size(); i++) {
        if (i != 0) {
            if (V[i] != V[i-1] + 1) {
                // process curchain
                if (curchain.size() % 2 == 0) {
                    int l = curchain.size() / 2;
                    int p1 = 1;
                    if (arr[curchain[0] - 1] == 0) p1 = 0;
                    for (int j = curchain[0]; j < curchain[0] + l; j++) arr[j] = p1;
                    for (int j = curchain[0] + l; j < curchain[0] + 2 * l; j++) arr[j] = !p1;
                    maxi = max(maxi, l);
                } else {
                    int p = !arr[curchain[0]];
                    for (int j = curchain[0]; j < curchain[0] + curchain.size(); j++) arr[j] = p;
                    maxi = max(maxi, (int)curchain.size() / 2 + 1);
                }
                curchain.clear();
            }
        }
        curchain.push_back(V[i]);
    }
    if (curchain.size() > 0) {
        if (curchain.size() % 2 == 0) {
            int l = curchain.size() / 2;
            int p1 = 1;
                    if (arr[curchain[0] - 1] == 0) p1 = 0;
                    for (int j = curchain[0]; j < curchain[0] + l; j++) arr[j] = p1;
                    for (int j = curchain[0] + l; j < curchain[0] + 2 * l; j++) arr[j] = !p1;
            maxi = max(maxi, l);
        } else {
            int p = !arr[curchain[0]];
            for (int j = curchain[0]; j < curchain[0] + curchain.size(); j++) arr[j] = p;
            maxi = max(maxi, (int)curchain.size() / 2 + 1);
        }
        curchain.clear();
    }
    printf("%d\n", maxi);
    for (int i = 0; i < N; i++) {
        if(i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}