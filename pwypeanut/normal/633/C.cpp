#include <bits/stdc++.h>
using namespace std;

int L, N, dp[10005], fr[10005], tr[10005];
string o, arr[100005], fx[100005];

struct node {
    node *p[26];
    vector<int> endings;
    node() {
        for (int i = 0; i < 26; i++) p[i] = NULL;
    }
    void cre(int s, int pos) {
        if (pos == fx[s].length()) {
            endings.push_back(s);
            return;
        }
        if (p[fx[s][pos] - 'a'] == NULL) p[fx[s][pos] - 'a'] = new node();
        p[fx[s][pos] - 'a']->cre(s, pos + 1);
    }
} *root;

void trace(int x) {
    if (x == 0) return;
    trace(fr[x]);
   // printf("reached: %d\n", x);
    printf("%s ", arr[tr[x]].c_str());
}

int main() {
//freopen("cat.txt", "r", stdin);
    scanf("%d", &L);
    cin >> o;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) fx[i] = arr[i];
    for (int i = 0; i < N; i++) for (int j = 0; j < fx[i].length(); j++) fx[i][j] = tolower(fx[i][j]);
    root = new node();
    for (int i = 0; i < N; i++) root->cre(i, 0);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= L; i++) {
        node *cur = root;
        for (int l = 1; l <= min(1000, i); l++) {
            char c = o[i - l];
            if (cur->p[c - 'a'] == NULL) break;
            cur = cur->p[c - 'a'];
            if (cur->endings.size() > 0 && dp[i - l]) {
                dp[i] = 1;
                fr[i] = i - l;
                tr[i] = cur->endings[0];
                break;
            }
        }
    }
    trace(L);
    printf("\n");
}