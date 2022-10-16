#include <cstdio>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int,int> index;
vector <int > left;
vector <int> li;
int n,m,a,b;


int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        index[x] = i;
        left.push_back(0);

    }
    for(int i = 0;i<m;i++){
        scanf("%d %d",&a,&b);
        int u1 = index[a];
        int u2 = index[b];
        int z = max(u1,u2);
        left[z]= max(left[z],min(u1,u2)+1);
    }
    long long int sol = 0;
    int u = 0;
    for(int i = 0;i<n;i++){
        u = max(u,left[i]);
        sol+=i-u+1;
    }
    printf("%I64d",sol);

}