#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  set<int> st;
  for(int i=1;i<=n;i++){st.insert(i);}
  vector<int> lm(n+5,-1e9),rm(n+5,1e9);
  vector<bool> safe(n+5,false);
  vector<bool> sick(n+5,false);
  while(q>0){
    q--;
    int typ;
    cin >> typ;
    if(typ==0){
      int l,r,x;
      cin >> l >> r >> x;
      if(x==0){
        int cl=-1e9,cr=1e9;
        while(!st.empty()){
          auto it=st.lower_bound(l);
          if(it==st.end()){break;}
          int tg=(*it);
          if(r<tg){break;}
          safe[tg]=true;
          cl=max(cl,lm[tg]);
          cr=min(cr,rm[tg]);
          st.erase(it);
        }
        auto it=st.lower_bound(l);
        if(it!=st.end()){
          int tg=(*it);
          //cout << tg << '\n';
          rm[tg]=min(rm[tg],cr);

          lm[tg]=min(lm[tg],tg);
          rm[tg]=max(rm[tg],tg);
          auto lit=st.lower_bound(lm[tg]);
          auto rit=st.lower_bound(rm[tg]+1);rit--;
          //cout << (*lit) << ' ' << (*rit) << '\n';
          if((*lit)==tg && (*rit)==tg){sick[tg]=true;}
          lm[tg]=max(lm[tg],(*lit));
          rm[tg]=min(rm[tg],(*rit));
        }
        if(it!=st.begin()){
          it--;
          int tg=(*it);
          //cout << tg << '\n';
          lm[tg]=max(lm[tg],cl);

          lm[tg]=min(lm[tg],tg);
          rm[tg]=max(rm[tg],tg);
          auto lit=st.lower_bound(lm[tg]);
          auto rit=st.lower_bound(rm[tg]+1);rit--;
          //cout << (*lit) << ' ' << (*rit) << '\n';
          if((*lit)==tg && (*rit)==tg){sick[tg]=true;}
          lm[tg]=max(lm[tg],(*lit));
          rm[tg]=min(rm[tg],(*rit));
        }
      }
      else{
        auto llit=st.lower_bound(l);
        auto rrit=st.lower_bound(r+1);rrit--;
        rm[(*llit)]=min(rm[(*llit)],(*rrit));
        lm[(*rrit)]=max(lm[(*rrit)],(*llit));
        //cout << "*" << (*llit) << ' ' << (*rrit) << '\n';
        {
          int tg=(*llit);

          lm[tg]=min(lm[tg],tg);
          rm[tg]=max(rm[tg],tg);
          auto lit=st.lower_bound(lm[tg]);
          auto rit=st.lower_bound(rm[tg]+1);rit--;
          //cout << (*lit) << ' ' << (*rit) << '\n';
          if((*lit)==tg && (*rit)==tg){sick[tg]=true;}
          lm[tg]=max(lm[tg],(*lit));
          rm[tg]=min(rm[tg],(*rit));
        }
        {
          int tg=(*rrit);

          lm[tg]=min(lm[tg],tg);
          rm[tg]=max(rm[tg],tg);
          auto lit=st.lower_bound(lm[tg]);
          auto rit=st.lower_bound(rm[tg]+1);rit--;
          //cout << (*lit) << ' ' << (*rit) << '\n';
          if((*lit)==tg && (*rit)==tg){sick[tg]=true;}
          lm[tg]=max(lm[tg],(*lit));
          rm[tg]=min(rm[tg],(*rit));
        }
      }
    }
    else{
      int x;
      cin >> x;
      if(safe[x]){cout << "NO\n";}
      else if(sick[x]){cout << "YES\n";}
      else{cout << "N/A\n";}
    }
  }
  return 0;
}