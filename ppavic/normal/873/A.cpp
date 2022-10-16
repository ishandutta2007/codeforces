#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,x,y;
vector < int > v;

int main(){
    scanf("%d%d%d",&n,&k,&x);
    for(int i = 0;i<n;i++){
        scanf("%d",&y);
        v.push_back(y);
    }
    sort(v.rbegin(),v.rend());
    int sol = 0;
    for(int i = 0;i<k;i++){
        sol += x;
    }
    for(int i = k;i<n;i++)
        sol += v[i];
    printf("%d\n",sol);
}