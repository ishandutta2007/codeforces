#include <cstdio>
#include <vector>

using namespace std;

int n,k,x,c = 0;
vector <int> v;

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++) v.push_back(i+1);
    for(int i = 0;i<k;i++){
        scanf("%d",&x);
        c += x;
        c %= v.size();
        printf("%d ",v[c]);
        v.erase(v.begin()+c);
        if(c == v.size()) c = 0;
    }
    printf("\n");
}