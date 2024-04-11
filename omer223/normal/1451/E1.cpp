#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int sz=(1 << 16) + 1;
int ans[sz], qu[sz];
int n;

int ask(int i, int j, string what) {
    i++;
    j++;
    cout<<what<<' '<<i<<' '<<j<<endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

void answer() {
    cout << "! ";
    foru(i, 0, n)cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    fast;
    cin >> n;
    foru(i,1,n)qu[i]=ask(0,i,"XOR");
    unordered_map<int, int> mem;
    bool found=0;
    foru(i,1,n){
        if(mem.find(qu[i])!=mem.end()){
            ans[0] = (ask(mem[qu[i]], i, "AND") ^ qu[i]);
            found=1;
            break;
        }
        else if (qu[i]==0){
            ans[0]=ask(i,0,"AND");
            found=1;
            break;
        }
        mem[qu[i]]=i;
    }
    if (!found) {
        const int msk = n - 1;
        int a = (1+(qu[1]==n-1)),b=mem[qu[a]^msk];
        ans[0]=(ask(0,a,"AND") | ask(0,b,"AND"));
    }
    foru(i,1,n)ans[i]=(ans[0]^qu[i]);
    answer();
    return 0;
}