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
int countSubstrings(vector<int> s) {
        int n = s.size(), i = 0, j = 0, count = 0;
        while (j < n) {
            while (j + 1 < n && s[j] == s[j + 1])
                j++;
            int tmp = j + 1, dupLength = j - i + 1;
            count += (1 + dupLength) * dupLength / 2;
            while (i - 1 >= 0 && j + 1 < n && s[i - 1] == s[j + 1]) {
                i--;
                j++;
                count++;
            }
            i = j = tmp;
        }
        return count;
    }
const int mod=1e9+7;
int powers[27];
int has(vector<int> tr)
{
    int h=0;
    for(int i=0;i<26;i++)
    {
        h=((ll)h*251+tr[i])%mod;
    }
    return h;
}
int main()
{
    powers[0]=1;
    for(int i=1;i<27;i++)
        powers[i]=((ll)powers[i-1]*251)%mod;
	int n,m;
	scanf("%i %i",&n,&m);
	vector<string> mat(n);
	for(int i=0;i<n;i++)
        cin >> mat[i];
    int h[n][m][m];
    bool pal[n][m][m];
    for(int i=0;i<n;i++)
    {
        for(int s=0;s<m;s++)
        {
            int ha=0;
            vector<int> tr(26);
            for(int j=0;j<s;j++)
            {
                tr[mat[i][j]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                ha=((ll)ha*251+tr[i])%mod;
            }
            for(int j=s;j<m;j++)
            {
                int t=mat[i][j]-'a';
                tr[t]++;
                ha=((ll)ha+powers[25-t])%mod;
                h[i][j-s][j]=ha;
                int cnt=0;
                for(int l=0;l<26;l++){
                    //if(tr[l]>0)
                    //printf("%i %i %i: %i %i\n",i,j-s,j,l,tr[l]);
                    if(tr[l]%2==1)
                        cnt++;
                }
                //printf("%i %i %i %i\n",i,j-s,j,cnt);
                if(cnt>1)
                    pal[i][j-s][j]=false;
                else
                    pal[i][j-s][j]=true;
                tr[mat[i][j-s]-'a']--;
                ha-=powers[25-mat[i][j-s]+'a'];
                if(ha<0)
                    ha+=mod;
            }
        }
    }
    ll res=0;
    for(int i=0;i<m;i++)
    {
        for(int j=i;j<m;j++)
        {
            vector<int> s;
            bool test=false;
            for(int k=0;k<n;k++)
            {
                s.pb(h[k][i][j]);
                if(!pal[k][i][j])
                {
                    s.pop_back();
                    res+=(ll)countSubstrings(s);
                    s.clear();
                }
                //printf("%i\n",h[k][i][j]);
            }
            //printf("%i %i %i %lld\n",i,j,countSubstrings(s),res);
            res+=(ll)countSubstrings(s);
        }
    }
    printf("%lld\n",res);
    return 0;
}