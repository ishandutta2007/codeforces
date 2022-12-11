#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = 1005;
int numbers[N];

int main(){
    int n,m,c;
    scanf("%d %d %d",&n,&m,&c);
    int req;
    int pos;
    bool sorted = false;
    while(m--){
        scanf("%d",&req);
        if(req>c/2){
            pos = n;
            while(pos>1){
                if(numbers[pos]<req)
                    break;// put the number in this position
                pos--;
            }
        }
        else{
            pos = 1;
            while(pos<n){
                if(numbers[pos]==0 or numbers[pos]>req)// fill an empty sheet or put in the best position
                    break;
                pos++;
            }
        }
        printf("%d\n",pos);
        numbers[pos]=req;
        for(int i = 1;i<=n;i++){
            if(numbers[i]==0)sorted=false;
            if(i>1)
                if(numbers[i]<numbers[i-1])sorted=false;
        }
        fflush(stdout);
        if(sorted)
            return 0;
    }
    return 0;
}