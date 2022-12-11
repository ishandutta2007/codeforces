#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int A[N][N];
int B[N][N];

int nx[3];
int dif[3];

int n;
void add(int &a, int b){
    a = (a + b + n) % n;
}

void solve(){
    int m;
    cin >> n >> m;
    nx[0] = 0;
    nx[1] = 1;
    nx[2] = 2;
    dif[0] = 0;
    dif[1] = 0;
    dif[2] = 0;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cin >> A[i][j];
            A[i][j] -- ;
        }
    }
    string t;
    cin >> t;
    int p[2];
    for(char x : t){
        if(x == 'L'){
            add(dif[1],-1);
        }
        else if(x == 'R'){
            add(dif[1],+1);
        }
        else if(x == 'U'){
            add(dif[0],-1);
        }
        else if(x == 'D'){
            add(dif[0],+1);
        }
        else if(x == 'I'){
            swap(dif[1],dif[2]);
            swap(nx[1],nx[2]);
        }
        else if(x == 'C'){
            swap(dif[0],dif[2]);
            swap(nx[0], nx[2]);
        }
    }
    int ii, jj, aa;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            vector<int> c = {i,j,A[i][j]};
            ii = c[nx[0]];
            jj = c[nx[1]];
            aa = c[nx[2]];
            add(ii,dif[0]);
            add(jj,dif[1]);
            add(aa,dif[2]);
            B[ii][jj]=aa;
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cout << B[i][j] + 1 << " ";
        }
        cout << "\n";
    }

}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}