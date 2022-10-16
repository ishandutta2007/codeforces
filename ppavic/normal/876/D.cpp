#include <cstdio>
#include <set>

using namespace std;

set < int > s;
int x,lst,n;

int main(){
    scanf("%d",&n);lst = n;
    printf("1\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        s.insert(x);
        while(!s.empty() && *(s.rbegin()) == lst){
            s.erase(*(s.rbegin()));lst--;
        }
        printf("%d\n",s.size()+1);
    }
}