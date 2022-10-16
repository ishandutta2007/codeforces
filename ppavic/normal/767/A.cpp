#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector < pair <int,int > > v;

int x;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        v.push_back(make_pair(x,i));
    }
    sort(v.rbegin(),v.rend());
    int j = 0;
    for(int i = 0;i<n;i++){
        while(j < v[i].second){
            printf("\n");j++;
        }
        printf("%d ",v[i].first);
    }
}