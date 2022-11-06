#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pp;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

int n, m;

int arr[int(1e5) + 10];

vector<pp> q;

int diff[int(1e5) + 10];

int main()
{
    read(n, m);
    int min_len = 2e9;
    for(int i=1; i<=m; ++i){
        int a,b; read(a, b); q.pb({a, b});
        min_len = min(min_len, b-a+1);
        ++diff[a]; --diff[b+1];
    }
    printf("%d\n", min_len);
    int hei = 0, rou = 0;
    for(int i=1; i<=n; ++i){
        hei += diff[i];
        if(hei){
            arr[i]=rou++;
            rou %= min_len;
        }
        printf("%d ",arr[i]);
    }
    
    return 0;
}