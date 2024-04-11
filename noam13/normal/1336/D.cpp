#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;
const int MAXN = 1e3;


ii last = {0,0};
ii ask(int i){
	if (i!=-1) cout<<"+ "<<(i+1)<<endl;
	int a,b; cin>>a>>b;
    a-=last.x, b-=last.y;
    last = {a+last.x, b+last.y};
	return {a,b};
}
int search(int v){
	loop(i,1,MAXN){
        if ((i*(i-1))/2==v) return i;
    }
    return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    ask(-1);
    vi ans(n);
    ii q1 = ask(0);
    ii q2 = ask(1);
    ii q3 = ask(2);
    ii q4 = ask(0);
    ans[0] = search(q4.x) + 1;
    if (q2.y==0) ans[2] = 1;
    else ans[2] = search(q3.x) + 1;
    ans[1] = q4.y / ans[2];
    int carry = q3.y - ans[1] * (ans[0] - 1);
    loop(i,3,n-1){
        ii qur = ask(i);
        if (carry==0)  ans[i] = 1;
        else ans[i] = search(qur.x) + 1;
        carry = qur.y - ans[i-1] * ans[i-2];
    }
    if (carry==0) ans[n-1]=0;
    else ans[n-1] = carry / ans[n-3];
    ans[0]--; loop(i,0,n-1) ans[i]--;
    cout<<"! "; loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a


*/