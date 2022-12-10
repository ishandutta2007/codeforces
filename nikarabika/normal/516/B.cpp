#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair

typedef pair<int, int> pie;

const int maxn = 2e3 + 10;
char S[maxn][maxn];
int p[maxn][maxn];
vector<pie > th;
int n, m, R;

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << S[i][j];
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    th.reserve(4000000);
    cin >> n >> m;
    for(int i = 0; i <= n + 1; i++){
        S[i][0] = (S[i][m + 1] = '*');
        p[i][1]++;
        p[i][m]++;
    }
    for(int j = 0; j <= m + 1; j++){
        S[0][j] = (S[n + 1][j] = '*');
        p[1][j]++;
        p[n][j]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> S[i][j];
            if(S[i][j] == '*'){
                p[i - 1][j]++;
                p[i + 1][j]++;
                p[i][j + 1]++;
                p[i][j - 1]++;
            }
            else
                R ++;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(S[i][j] == '.' and p[i][j] == 3)
                th.PB(MP(i, j));
    if(R & 1){
        cout << "Not unique" << endl;
        return 0;
    }
    while(th.size() and R){
        int x = th.back().first, y = th.back().second;
        th.pop_back();
        if(x > n or x < 1 or y < 1 or y > m or S[x][y] != '.')
            continue;
        if(S[x][y + 1] == '.'){
            S[x][y] = '<';
            S[x][y + 1] = '>';
            if(y + 2 <= m + 1){
                p[x][y + 2] ++;
                if(p[x][y + 2] == 3)
                    th.PB(MP(x, y + 2));
            }
            p[x - 1][y + 1]++;
            if(p[x - 1][y + 1] == 3)
                th.PB(MP(x - 1, y + 1));
            p[x + 1][y + 1]++;
            if(p[x + 1][y + 1] == 3)
                th.PB(MP(x + 1, y + 1));
        }
        else if(S[x][y - 1] == '.'){
            S[x][y] = '>';
            S[x][y - 1] = '<';
            if(y - 2 >= 0){
                p[x][y - 2] ++;
                if(p[x][y - 2] == 3)
                    th.PB(MP(x, y - 2));
            }
            p[x - 1][y - 1]++;
            if(p[x - 1][y - 1] == 3)
                th.PB(MP(x - 1, y - 1));
            p[x + 1][y - 1]++;
            if(p[x + 1][y - 1] == 3)
                th.PB(MP(x + 1, y - 1));
        }
        else if(S[x + 1][y] == '.'){
            S[x][y] = '^';
            S[x + 1][y] = 'v';
            if(x + 2 <= n + 1){
                p[x + 2][y] ++;
                if(p[x + 2][y] == 3)
                    th.PB(MP(x + 2, y));
            }
            p[x + 1][y - 1]++;
            if(p[x + 1][y - 1] == 3)
                th.PB(MP(x + 1, y - 1));
            p[x + 1][y + 1]++;
            if(p[x + 1][y + 1] == 3)
                th.PB(MP(x + 1, y + 1));
        }
        else if(S[x - 1][y] == '.'){
            S[x][y] = 'v';
            S[x - 1][y] = '^';
            if(x - 2 >= 0){
                p[x - 2][y] ++;
                if(p[x - 2][y] == 3)
                    th.PB(MP(x - 2, y));
            }
            p[x - 1][y - 1]++;
            if(p[x - 1][y - 1] == 3)
                th.PB(MP(x - 1, y - 1));
            p[x - 1][y + 1]++;
            if(p[x - 1][y + 1] == 3)
                th.PB(MP(x - 1, y + 1));
        }
        else{
            cout << "Not unique" << endl;
            return 0;
        }
        R -= 2;
    }
    if(R == 0)
        print();
    else
        cout << "Not unique" << endl;
    return 0;
}