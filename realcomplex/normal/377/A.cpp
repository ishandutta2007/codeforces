#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second
#define t abs

int main(){

    int n,m,k;
    cin >> n >> m >> k;
    int lab[n+2][m+2];
    bool f = false;
    queue<pair<int,int> >w;
    for(int i = 0;i<=n+1;i++){
        for(int x = 0;x<=m+1;x++){
            lab[i][x] = -1;
        }
    }
    char s;
    for(int i = 1;i<=n;i++){
        for(int x = 1;x<=m;x++){
            cin >> s;
            if(s == '.'){
                lab[i][x] = 1e9;
                if(f == false){
                    w.push(mp(i,x));
                    lab[i][x] = 0;
                    f = true;
                }
            }
        }
    }
    int fc,sc;
    while(w.size()>0){
        fc = w.front().f;
        sc = w.front().s;
        if(lab[fc][sc+1] == 1e9){
            lab[fc][sc+1] = lab[fc][sc]+1;
            w.push(mp(fc,sc+1));
        }
        if(lab[fc][sc-1] == 1e9){
            lab[fc][sc-1] = lab[fc][sc]+1;
            w.push(mp(fc,sc-1));
        }
        if(lab[fc-1][sc] == 1e9){
            lab[fc-1][sc] = lab[fc][sc]+1;
            w.push(mp(fc-1,sc));
        }
        if(lab[fc+1][sc] == 1e9){
            lab[fc+1][sc] = lab[fc][sc]+1;
            w.push(mp(fc+1,sc));
        }
        w.pop();
    }
    int depth = 0;
    for(int i = 1;i<=n;i++){
        for(int x = 1;x<=m;x++){
            depth = max(lab[i][x],depth);
        }
    }
    vector<pair<int,int> >e[depth+1];
    for(int i = 1;i<=n;i++){
        for(int x = 1;x<=m;x++){
            if(lab[i][x] != -1){
                e[lab[i][x]].push_back(mp(i,x));
            }
        }
    }
    for(int i = depth;i>0 && k>0;i--){
        for(int x = 0;x<e[i].size() && k>0;x++){
            lab[e[i][x].f][e[i][x].s] = -4;
            k--;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int x = 1;x<=m;x++){
            if(lab[i][x] == -4){
                cout << "X";
            }
            else if(lab[i][x] == -1){
                cout << "#";
            }
            else{
                cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}