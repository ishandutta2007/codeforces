#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;
int k, a, h;
ll p[18];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> a >> h;
	p[0]=1;
	for (int i=1; i<18; ++i)
		p[i]=p[i-1]*a%M;
	if (k==1) {
		if ((p[1]+2*p[2])%M==h)
			cout << "1 2";
		else if ((p[2]+2*p[1])%M==h)
			cout << "2 1";
		else
			cout << -1;
	} else if (k<=4) { // brute force
		for (int mask=0; mask<(1<<(1<<k)-1); ++mask) {
			vector<int> v(1<<k), ans(1<<k);
			iota(v.begin(), v.end(), 1);
			ll hsh=0;
			int cmask=mask;
			for (int i=k-1; i; --i) {
				assert(v.size()==(1<<i+1));
				vector<int> nv;
				for (int j=0; j<(1<<i+1); j+=2) {
					int bit=cmask%2;
					cmask/=2;
					hsh=(hsh+v[j+(bit^1)]*p[(1<<i)+1])%M;
					ans[v[j+(bit^1)]-1]=(1<<i)+1;
					nv.push_back(v[j+bit]);
				}
				swap(v, nv);
			}
			assert(cmask<2&&v.size()==2);
			hsh=(hsh+v[cmask]*p[1]+v[cmask^1]*p[2])%M;
			ans[v[cmask]-1]=1, ans[v[cmask^1]-1]=2;
			if (hsh==h) {
				for (int i : ans)
					cout << i << " ";
				return 0;
			}
		}
		cout << -1;
	} else {
		assert(k==5);
		vector<int> sum(1<<16);
		for (int mask=0; mask<(1<<16); ++mask) {
			int cmask=mask;
			for (int i=0; i<8; ++i) {
				int which=cmask&3;
				cmask/=4;
				which=(which/2)^1;
				sum[mask]+=4*i+2*which+1;
			}
		}
		assert(*min_element(sum.begin(), sum.end())==120&&*max_element(sum.begin(), sum.end())==136);
		vector<ll> pc(200);
		for (int i=120; i<=136; ++i)
			pc[i]=(i*p[17]+(i+8)*p[9])%M;
		int v[32], nv[32];
		for (int mask=0; mask<(1<<23); ++mask) {
			//if (mask%1000000==999999)
			//	cout << mask << endl;
			int cmask=mask;
			ll hsh=0;
			//vector<int> v(8);
			for (int i=0; i<8; ++i) {
				int which=cmask&3;
				cmask/=4;
				v[i]=4*i+which+1;
				hsh=(hsh+(4*i+(which^1)+1)*p[17])%M;
			}
			for (int i=2; i; --i) {
				//assert(v.size()==(1<<i+1));
				//vector<int> nv(1<<i);
				for (int j=0; j<(1<<i+1); j+=2) {
					int bit=cmask%2;
					cmask/=2;
					hsh=(hsh+v[j+(bit^1)]*p[(1<<i)+1])%M;
					nv[j/2]=v[j+bit];
				}
				for (int j=0; j<(1<<i); ++j)
					v[j]=nv[j];
				//swap(v, nv);
			}
			//assert(cmask<2&&v.size()==2);
			hsh=(hsh+v[cmask]*p[1]+v[cmask^1]*p[2])%M;
			hsh=(hsh+pc[sum[mask&((1<<16)-1)]])%M;
			int ind=-1;
			for (int i=0; i<=8; ++i) {
				ll cur=(hsh+(p[17]-p[9]+M)*i)%M;
				if (cur==h) {
					ind=i;
					break;
				}
			}
			if (ind!=-1) {
				vector<int> ans(32, 17);
				cmask=mask;
				//v.resize(8);
				for (int i=0; i<8; ++i) {
					int which=cmask&3;
					cmask/=4;
					v[i]=4*i+which+1;
				}
				for (int i=2; i; --i) {
					//assert(v.size()==(1<<i+1));
					//vector<int> nv(1<<i);
					for (int j=0; j<(1<<i+1); j+=2) {
						int bit=cmask%2;
						cmask/=2;
						nv[j/2]=v[j+bit];
						ans[v[j+(bit^1)]-1]=(1<<i)+1;
					}
					for (int j=0; j<(1<<i); ++j)
						v[j]=nv[j];
					//swap(v, nv);
				}
				//assert(cmask<2&&v.size()==2);
				ans[v[cmask]-1]=1, ans[v[cmask^1]-1]=2;
				
				//v.clear();
				cmask=mask&((1<<16)-1);
				for (int i=0; i<8; ++i) {
					int which=cmask&3;
					cmask/=4;
					which=(which/2)^1;
					v[i]=4*i+2*which;
					ans[4*i+2*which+1]=9;
				}
				//assert(v.size()==8);
				for (int i=0; i<ind; ++i)
					swap(ans[v[i]], ans[v[i]+1]);
				for (int i : ans)
					cout << i << " ";
				return 0;
			}
		}
		cout << -1;
	}
	return 0;
}