#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 207;
char s[2][MAX_N];

void TestCase() {
    scanf("%s%s", s[0], s[1]);
    vector<vector<int>>cnt(2, vector<int>(3, 0));
    vector<int>v[2] = {vector<int>(), vector<int>()};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; s[i][j] != 0; j++) {
            cnt[i][s[i][j] - 'A']++;
            if(s[i][j] == 'B')
                continue;
            if(!v[i].empty() && v[i].back() == s[i][j]) {
                v[i].pop_back();
            } else {
                v[i].push_back(s[i][j]);
            }
        }
    }
    
    for(int i = 0; i < 3; i++) {
        if(cnt[0][i] % 2 != cnt[1][i] % 2) {
            printf("NO\n");
            return;
        }
    }
    
    if(v[0] == v[1]) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--)
        TestCase();
    return 0;
}