#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n;
vector<vector<int> > R;

void make(int step){
    if(step >= n) return;
    make(step*2);
    R.push_back(vector<int>());
    for(int i=0; i<n; i+=2*step)
        for(int j=i; j<min(i+step,n); ++j)
            R.back().push_back(j+1);
}

int main(){
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    make(1);
    printf("%d\n", R.size());
    FE(r,R){
        printf("%d ", (*r).size());
        FE(e,*r) printf("%d ", *e);
        printf("\n");
    }
    return 0;
}