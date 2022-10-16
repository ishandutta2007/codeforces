#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int llint;

int n;

llint cur,s,f,t,x;
llint sol = -1,mi = 1e13;

vector <llint> v;

int main(){
    scanf("%I64d %I64d %I64d %I64d",&s,&f,&t,&n);
    cur = s;
    if(n == 0){
        printf("%I64d\n",cur);
        return 0;
    }
    for(int i = 0;i<n;i++){
        scanf("%I64d",&x);
        v.push_back(x);
    }
    mi = cur - (v[0]- 1);
    sol = v[0] -  1;
    cur += t;
    for(int i = 1;i<n;i++){
        if(v[i-1] < v[i]-1 && cur - (v[i]- 1) < mi){
            mi = cur - (v[i]- 1);
            sol = v[i] - 1;
        }
        cur = max(cur+t,v[i]+t);
        if(cur >= f) break;
    }
    if(cur + t -1 < f){
        sol = cur;
    }
    printf("%I64d\n",sol);
}