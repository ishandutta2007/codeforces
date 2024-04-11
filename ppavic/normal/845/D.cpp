#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,ty,a,b,cc = 0,sped = 0;

stack < int > lim;
stack < int > over;

int main(){
    lim.push(INF);
    over.push(1);
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&ty);
        if(ty == 1){
            scanf("%d",&a);
            sped = a;
            while(lim.top() < a){
                lim.pop();
                cc++;
            }
        }
        if(ty == 2){
            while(over.top() == 0){
                over.pop();
                cc++;
            }
        }
        if(ty == 3){
            scanf("%d",&a);
            if(sped > a) cc++;
            else lim.push(a);
        }
        if(ty == 4){
            over.push(1);
        }
        if(ty == 5){
            lim.push(INF);
        }
        if(ty == 6){
            over.push(0);
        }
    }
    printf("%d\n",cc);
}