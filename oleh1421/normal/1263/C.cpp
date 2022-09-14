#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve(){
	int n;cin>>n;
    set<int>st;
    st.insert(0);
    for (int i=1;i*i<=n;i++){
        st.insert(n/i);
        st.insert(i);
    }
    cout<<st.size()<<endl;
    for (auto i:st) cout<<i<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int tt;cin>>tt;
	while(tt--){
		solve();
	}
	return 0;
}