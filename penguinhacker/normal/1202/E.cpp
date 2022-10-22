#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

//source: cp-algorithms
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
	vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> get_suf_arr(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int n, cnt1[200000], cnt2[200000];
string s[200000], t;

int sign(string &s, int pos) { //1 if t(pos, end) > s
	for (int i=0; i<s.size()&&i+pos<t.size(); ++i) {
		if (s[i]==t[i+pos]) continue;
		return t[i+pos]>s[i]?1:-1;
	}
	if (s.size()>t.size()-pos) return -1; //too small
	return 0; //equal
}

void solve(int ans[]) {
	vector<int> ord=get_suf_arr(t);
	vector<int> pre(t.size()+1);
	for (int i=0; i<n; ++i) {
		int l=0, r=t.size()-1;
		while(l<r) {
			int mid=(l+r)/2, pos=ord[mid];
			int x=sign(s[i], pos);	
			if (x>=0) r=mid;
			else l=mid+1;
		}
		if (sign(s[i], ord[l])!=0) continue;
		/*for (int j=0; j<t.size(); ++j)
			cout << sign(s[i], ord[j]) << ' ';
		cout << '\n';*/
		//cout << l << ' ';
		++pre[l];
		l=0, r=t.size()-1;
		while(l<r) {
			int mid=(l+r+1)/2, pos=ord[mid];
			int x=sign(s[i], pos);
			if (x<=0) l=mid;
			else r=mid-1;
		}
		//cout << l << '\n';
		--pre[l+1];
	}
	//cout << '\n';
	for (int i=0; i<t.size(); ++i) {
		pre[i]+=i?pre[i-1]:0;
		ans[ord[i]]=pre[i];
		//cout << ord[i] << ' ' << pre[i] << '\n';
	}
	//cout << "\n\n\n";
	reverse(t.begin(), t.end());
	for (int i=0; i<n; ++i)
		reverse(s[i].begin(), s[i].end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	solve(cnt2);
	//for (int i=0; i<t.size(); ++i)
	//	cout << cnt2[i] << '\n';
	solve(cnt1);
	reverse(cnt1, cnt1+t.size());

	ll ans=0;
	for (int i=0; i+1<t.size(); ++i) {
		//cout << cnt1[i] << ' ' << cnt2[i] << '\n';
		ans+=1ll*cnt1[i]*cnt2[i+1];
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/