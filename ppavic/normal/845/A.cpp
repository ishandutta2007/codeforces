#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

vector < int > s;
int n,x;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<2 * n;i++){
        scanf("%d",&x);
        s.push_back(x);
    }
    sort(s.rbegin(),s.rend());
    if(s[n - 1] > s[n]){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}