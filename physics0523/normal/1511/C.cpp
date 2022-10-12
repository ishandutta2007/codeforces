#include<bits/stdc++.h>

using namespace std;

//Binary Indexed Tree
int bit[1050000]={0},bsize=1048576;
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
void add(int i,int x){
    while(i<=bsize){
        bit[i]+=x;
        i+=i&(-i);
    }
}


using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  int pos=400000;
  set<pi> st;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    st.insert(make_pair(v,pos+i));
    add(pos+i,1);
  }
  for(int i=0;i<q;i++){
    pos--;
    int v;
    cin >> v;
    pi tg=*(st.lower_bound(make_pair(v,-1)));
    int cp=tg.second;
    cout << sum(cp) << '\n';
    add(cp,-1);
    add(pos,1);
    st.insert(make_pair(v,pos));
  }
  return 0;
}