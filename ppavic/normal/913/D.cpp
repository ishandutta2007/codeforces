#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < int,int > pii;
typedef pair < ll ,ll > pll;
typedef pair < double, double > pdd;
typedef pair < pii, int > ppi;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int lo = 0,hi,n,k,T;
vector < ppi > v;

bool check(int k){
    vector < int > t;
    int x = k,sol = 0;
    for(int i = 0;i<v.size();i++){
        if(v[i].X.Y >= k && x > 0){
            sol += v[i].X.X;
            x--;
        }
    }
    return x == 0 && sol <= T;
}

void ispis(int k){
    vector < int > t;
    printf("%d\n%d\n",k,k);
    int x = k,sol = 0;
    for(int i = 0;i<v.size();i++){
        if(v[i].X.Y >= k && x > 0){
            printf("%d ",v[i].Y);
            sol += v[i].X.X;x--;
        }
    }
}

int main(){
    scanf("%d%d",&n,&T);
    for(int i = 0;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        v.push_back(make_pair(make_pair(y,x),i + 1));
    }
    sort(v.begin(),v.end());
    int lo = 0,hi = n,fin = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            fin = max(fin,mid);
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    ispis(fin);
}