#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int llint;

const int N = 1e5 + 500;

int p[N],n,bio[N];
vector < int > cik;

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",p+i);
    }
    for(int i = 1;i<=n;i++){
        if(bio[i]) continue;
        int siz = 0;
        while(!bio[i]){
            bio[i] = 1;
            siz++;i = p[i];
        }
        cik.push_back(siz);
    }
    llint sol = 0;
    sort(cik.rbegin(),cik.rend());
    if(cik.size() == 1){
        sol = (llint)n * n;
    }
    else{
        cik[1] += cik[0];
        for(int i = 1;i<cik.size();i++){
            sol += (llint)cik[i] * cik[i];
        }
    }
    printf("%I64d\n",sol);
}