#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}

int main()
{
    int n;
    scanf("%i",&n);
    string s;
    cin >> s;
    int cnt[3]={};
    for(auto p:s)
        cnt[p-'0']++;
    string sol;
    int broj[3]={};
    for(auto p:s)
    {
        if(cnt[p-'0']>n/3)
        {
            if(p=='0')
            {
                if(broj[0]<n/3)
                {
                    broj[0]++;
                    sol+='0';
                    continue;
                }
                if(cnt[1]<n/3)
                {
                    sol+='1';
                    cnt[0]--;
                    cnt[1]++;
                    broj[1]++;
                    continue;
                }
                sol+='2';
                cnt[0]--;
                cnt[2]++;
                broj[2]++;
                continue;
            }
            if(p=='1')
            {
                if(cnt[0]<n/3)
                {
                    sol+='0';
                    cnt[1]--;
                    cnt[0]++;
                    broj[0]++;
                    continue;
                }
                if(broj[1]<n/3)
                {
                    broj[1]++;
                    sol+='1';
                    continue;
                }
                sol+='2';
                cnt[1]--;
                cnt[2]++;
                broj[2]++;
                continue;
            }
            if(cnt[0]<n/3)
            {
                sol+='0';
                cnt[2]--;
                cnt[0]++;
                broj[0]++;
                continue;
            }
            sol+='1';
            cnt[2]--;
            cnt[1]++;
            broj[1]++;
            continue;
        }
        else
            sol+=p;
    }
    cout << sol << endl;
    return 0;
}