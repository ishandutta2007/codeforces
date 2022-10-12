#include<bits/stdc++.h>

using namespace std;

// linear recurrence relation[senkei-zenkashiki]
// S := first.size() == relation.size()
// A[i] (0-indexed) :=
// A[i] = first[i] (i < S)
// next terms are:
// A[i] = A[i-1]*relation[0] + A[i-2]*relation[1] + ...

// return : A[n] (0-indexed)

long long linear_recurrence(long long n,vector<long long> first,vector<long long> relation,long long mod){
  long long s=relation.size();
  if(n<s){return first[n];}
  reverse(first.begin(),first.end());
  vector<vector<long long>> mat(s);
  mat[0]=relation;
  for(int i=1;i<s;i++){
    mat[i].resize(s);
    for(int j=0;j<s;j++){
      if((i-1)==j){mat[i][j]=1;}else{mat[i][j]=0;}
    }
  }
  n-=s;n++;
  while(n>0){
    if(n%2){
      vector<long long> nvec(s,0);
      for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
          nvec[i]+=mat[i][j]*first[j];
          nvec[i]%=mod;
        }
      }
      swap(first,nvec);
    }
    vector<vector<long long>> nmat(s,vector<long long>(s,0));
    for(int i=0;i<s;i++){
      for(int j=0;j<s;j++){
        for(int k=0;k<s;k++){
          nmat[i][j]+=mat[i][k]*mat[k][j];
          nmat[i][j]%=mod;
        }
      }
    }
    swap(mat,nmat);
    n/=2;
  }
  return first[0];
}

// https://judge.yosupo.jp/submission/6332
typedef long long int ll;
//using ll=__int128_t;
typedef pair<ll, int> P;
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
ll powmod(ll a, ll k, ll mod){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=mod;
        }
        ap=ap*ap;
        ap%=mod;
        k>>=1;
    }
    return ans;
}
ll inv(ll a, ll m){
    ll b=m, x=1, y=0;
    while(b>0){
        ll t=a/b;
        swap(a-=t*b, b);
        swap(x-=t*y, y);
    }
    return (x%m+m)%m;
}
vector<P> fac(ll x){
	vector<P> ret;
	for(ll i=2; i*i<=x; i++){
		if(x%i==0){
			int e=0;
			while(x%i==0){
				x/=i;
				e++;
			}
			ret.push_back({i, e});
		}
	}
	if(x>1) ret.push_back({x, 1});
	return ret;
}
//mt19937_64 mt(334);
mt19937 mt(334);
ll solve1(ll p, ll q, int e, ll a){
    int s=0;
    ll r=p-1, qs=1, qp=1;
    while(r%q==0){
        r/=q;
        qs*=q;
        s++;
    }
    for(int i=0; i<e; i++) qp*=q;
    ll d=qp-inv(r%qp, qp);
    ll t=(d*r+1)/qp;
    ll at=powmod(a, t, p), inva=inv(a, p);
    if(e>=s){
        if(powmod(at, qp, p)!=a) return -1;
        else return at;
    }
    //uniform_int_distribution<long long> rnd(1, p-1);
	uniform_int_distribution<> rnd(1, p-1);
    ll rv;
    while(1){
        rv=powmod(rnd(mt), r, p);
        if(powmod(rv, qs/q, p)!=1) break;
    }
    int i=0;
    ll qi=1, sq=1;
    while(sq*sq<q) sq++;
    while(i<s-e){
        ll qq=qs/qp/qi/q;
        vector<P> v(sq);
        ll rvi=powmod(rv, qp*qq*(p-2)%(p-1), p), rvp=powmod(rv, sq*qp*qq, p);
        ll x=powmod(powmod(at, qp, p)*inva%p, qq*(p-2)%(p-1), p), y=1;
        for(int j=0; j<sq; j++){
            v[j]=P(x, j);
            (x*=rvi)%=p;
        }
        sort(v.begin(), v.end());
        ll z=-1;
        for(int j=0; j<sq; j++){
            int l=lower_bound(v.begin(), v.end(), P(y, 0))-v.begin();
            if(v[l].first==y){
                z=v[l].second+j*sq;
                break;
            }
            (y*=rvp)%=p;
        }
        if(z==-1) return -1;
        (at*=powmod(rv, z, p))%=p;
        i++;
        qi*=q;
        rv=powmod(rv, q, p);
    }
    return at;
}
ll solve0(ll p, ll q, ll r, ll a){
    ll d=q-inv(r%q, q);
    ll t=(d*r+1)/q;
    ll at=powmod(a, t, p), inva=inv(a, p);
    if(powmod(at, q, p)!=a) return -1;
    else return at;
}
ll solve(ll p, ll k, ll a){
	if(k==0){
		if(a==1) return 1;
		else return -1;
	}
	if(a==0){
		return 0;
	}
    if(p==2 || a==1) return 1;
    ll a1=a;
    ll g=gcd(p-1, k);
    ll c=inv(k/g%((p-1)/g), (p-1)/g);
    a=powmod(a, c, p);
    if(g==1){
        if(powmod(a, k, p)==a1) return a;
        else return -1;
    }
    ll g1=gcd(g, (p-1)/g), g2=g;
    vector<P> f1=fac(g1), f;
    for(auto r:f1){
        ll q=r.first;
        int e=0;
        while(g2%q==0){
            g2/=q;
            e++;
        }
        f.push_back({q, e});
    }
    ll ret=1, gp=1;
    if(g2>1){
        ll x=solve0(p, g2, (p-1)/g2, a);
        if(x==-1) return -1;
        ret=x, gp*=g2;
    }
    for(auto r:f){
        ll qp=1;
        for(int i=0; i<r.second; i++) qp*=r.first;
        ll x=solve1(p, r.first, r.second, a);
        if(x==-1) return -1;
        if(gp==1){
            ret=x, gp*=qp;
            continue;
        }
        ll s=inv(gp%qp, qp), t=(1-gp*s)/qp;
        if(t>=0) ret=powmod(ret, t, p);
        else ret=powmod(ret, p-1+t%(p-1), p);
        if(s>=0) x=powmod(x, s, p);
        else x=powmod(x, p-1+s%(p-1), p);
        (ret*=x)%=p;
        gp*=qp;
    }
    if(powmod(ret, k, p)!=a1) return -1;
    return ret;
}

long long p=998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long k;
  cin >> k;
  vector<long long> b(k),fir(k,0);
  fir[k-1]=1;
  for(auto &nx : b){cin >> nx;}
  long long n,m;
  cin >> n >> m;
  long long v=linear_recurrence(n-1,fir,b,p-1);
  cout << solve(p,v,m) << '\n';
  return 0;
}