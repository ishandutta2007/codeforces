#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int sol[100];

int ask1(int p, int q, int x){
    cout << "? " << 1 << " " << p << " " << q << " " << x << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

int ask2(int p, int q, int x){
    cout << "? " << 2 << " " << p << " " << q << " " << x << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

int getmax(int i, int j){
    int res = ask1(i, j, n - 1);
    if(res == n - 1){
        int chk = ask1(j, i, n - 1);
        return chk;
    }
    return res;
}

int getmin(int i, int j){
    int res = ask2(i, j, 1);
    if(res == 2){
        int chk = ask2(j, i, 1);
        return chk;
    }
    return res;
}

const int N = (int)1e4 + 10;
int P[N];

void shuffle(vector<int> &shit){
    int m = shit.size();
    int xx, yy;
    for(int i = 0 ; i < m * 5; i ++ ){
        xx = ((int)rng() % m + m) % m;
        yy = ((int)rng() % m + m) % m;
        swap(shit[xx], shit[yy]);
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        cin >> n;
        vector<int> ord;
        for(int i = 1; i <= n; i ++ ){
            ord.push_back(i);
        }
        shuffle(ord);
        //reverse(ord.begin(), ord.end());
        int A[2], B[2];
        A[0] = getmin(ord[0], ord[1]);
        A[1] = getmax(ord[0], ord[1]);
        B[0] = getmin(ord[1], ord[2]);
        B[1] = getmax(ord[1], ord[2]);
        for(int p = 0 ; p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                if(A[p] == B[q]){
                    P[ord[0]] = A[(p^1)];
                    P[ord[1]] = A[p];
                    P[ord[2]] = B[(q^1)];
                }
            }
        }
        int big = 0;
        for(int i = 0 ; i < 3; i ++ ){
            if(P[ord[i]] > P[ord[big]])
                big = i;
        }
        int rr;
        for(int i = 3; i < n; i ++ ){
            rr = getmin(ord[i], ord[big]);
            if(rr != P[ord[big]]){
                P[ord[i]] = rr;
            }
            else{
                P[ord[i]] = getmax(ord[i], ord[big]);
                big = i;
            }
        }
        cout << "! ";
        for(int i = 1; i <= n; i ++ ){
            cout << P[i] << " ";
        }
        cout << endl;
        fflush(stdout);
    }
    return 0;
}