#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 3e5 + 500;
const int INF = 0x3f3f3f3f;

char p[N];

vector < int > pek;
vector < int > ast;

int sol = INF,n;

int dist(int l, int r, int x){
    if(ast[l] < pek[x] && ast[r] < pek[x]) return abs(ast[l] - pek[x]);
    if(ast[l] > pek[x] && ast[r] > pek[x]) return abs(ast[r] - pek[x]);
    return min(abs(pek[x] - ast[l]) * 2 + abs(pek[x] - ast[r]) , abs(pek[x] - ast[r]) * 2 + abs(pek[x] - ast[l]));
}

bool check(int x){
    int l = 0,r = 0,st = 0;
    while(st < pek.size() && dist(0,0,st) > x) st++;
    for(int i = st;i<pek.size();i++){
        while(r < ast.size() && dist(l, r, i) <= x) r++;
        if(r == ast.size()) return 1;
        l = r;
    }
    return 0;
}




int main(){
    scanf("%d",&n);
    scanf("%s", p);
    for(int i = 0;i<n;i++){
        if(p[i] == '*') ast.push_back(i);
        if(p[i] == 'P') pek.push_back(i);
    }
    int lo=0, hi=N, sol;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            hi=mid;
        }
        else {
            lo=mid+1;
        }
    }
    printf("%d\n",lo);
}