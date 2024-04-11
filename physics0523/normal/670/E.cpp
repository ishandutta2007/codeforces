#include<bits/stdc++.h>

using namespace std;

// https://qiita.com/drken/items/1b7e6e459c24a83bb7fd
template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;                     // to be set

    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) {
        dat.resize(n + 1);
        for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
    }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* k-th number (k is 1-indexed) */
    int get(long long k) {
        //++k;
        int res = 0;
        int N = 1; while (N < (int)dat.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)dat.size() && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  BIT<int> bt(524288);
  int n,m,p;
  cin >> n >> m >> p;

  for(int i=1;i<=n;i++){bt.add(i,1);}

  string s,t;
  cin >> s >> t;
  for(int i=0;i<m;i++){
    //cout << p << ' ' << n << '\n';
    if(t[i]=='R'){p=min(n,p+1);}
    else if(t[i]=='L'){p=max(1,p-1);}
    else{
      int dlt;
      if(s[bt.get(p)-1]=='('){dlt=1;}else{dlt=-1;}
      int floor=0;
      int q=p;
      while(1){
        if(s[bt.get(q)-1]=='('){floor++;}else{floor--;}
        if(floor==0){break;}
        q+=dlt;
      }
      if(p>q){swap(p,q);}
      //s.erase(p,q-p+1);
      for(int j=q;j>=p;j--){
        n--;
        bt.add(bt.get(j),-1);
      }

      if(p>n){p=n;}
    }
  }
  for(int i=1;i<=n;i++){
    //cout << bt.get(i) << '\n';
    cout << s[bt.get(i)-1];
  }
  cout << '\n';
  return 0;
}