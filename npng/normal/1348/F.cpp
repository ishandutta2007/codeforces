#include <bits/stdc++.h>

using namespace std;
int n, kezd[200002], veg[200002], pos[200002], inv[200002], x, csa, csb;
vector<pair<pair<int, int>, int> > sz;
vector<int> v;
priority_queue<pair<int, int> > q;
void p() {
    for (int i=1; i<=n; i++) inv[pos[i]]=i;
    for (int i=1; i<=n; i++) cout << inv[i] << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b, kezd[i]=a, veg[i]=b;
        sz.push_back({{a, b}, i});
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<=n; i++) {
        while(x<n && sz[x].first.first==i) q.push({-sz[x].first.second, sz[x].second}), x++;
        pos[i]=q.top().second, q.pop();
    }
    for (int i=1; i<=n; i++) {
        while(v.size()>0 && veg[pos[v.back()]]<i) {
            v.pop_back();
        }
        int a=kezd[pos[i]], b=veg[pos[i]];
        if (v.size()>0 && a<=v.back()) {
            csa=i, csb=v.back();
        }
        while(v.size()>0 && b>=veg[pos[v.back()]]) v.pop_back();
        v.push_back(i);
    }
    if(!csa){
        cout<<"YES"<<"\n";
        p();
    }
	else{
        cout<<"NO"<<"\n";
        p();
		swap(pos[csa],pos[csb]);
		p();
    }
    return 0;
}