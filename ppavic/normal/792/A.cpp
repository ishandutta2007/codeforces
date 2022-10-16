#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
int n,x;
int mi = 2e9+1,cnt = 0;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i = 1;i<v.size();i++){
        if(v[i] - v[i-1] < mi)
            mi = v[i] - v[i-1],cnt = 0;
        if(v[i] - v[i-1] == mi)
            cnt++;
    }
    printf("%d %d\n",mi,cnt);
}