#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>


using namespace std;
typedef long long LL;
const LL MOD=1000000007;

typedef vector<LL> ARY;
typedef vector<ARY> MAT;


string s, e;
int k, n;

MAT mulMod(const MAT&a, const MAT&b){
  MAT r(3, ARY(3, 0));
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      for(int k=0; k<3; k++)
	r[i][j]=(r[i][j]+(LL)a[i][k]*b[k][j])%MOD;
  
  return r;
}
    

MAT powMod(const MAT&x, int y){
  if(y==1)return x;
  if(y%2)return mulMod(x, powMod(x, y-1));
  return powMod(mulMod(x, x), y/2);
}

int akr(string t, int p){
  int i;
  for(i=0; i<n; i++)if(e[i]!=t[(i+p)%n])break;
  if(i==n)return 0;

  for(i=0; i<n; i++)if(s[i]!=t[(i+p)%n])break;
  if(i==n)return 1;

  return 2;
}

int main(){
  
  cin>>s>>e;
  scanf("%d", &k);
  n=s.size();

  if(k==0){printf("%d\n", s==e);return 0;}
  
  
  MAT mat(3, ARY(3, 0));

  vector<string>v;

  for(int i=0; i<n; i++)
    v.push_back(s.substr(i)+s.substr(0, i));

  for(int x=0; x<n; x++){
    if(v[x]==e){
      for(int i=1; i<n; i++)
	mat[akr(e, i)][0]++;
      break;
    }
  }

  for(int i=1; i<n; i++)
    mat[akr(s, i)][1]++;

  for(int x=0; x<n; x++){
    if(v[x]!=e && v[x]!=s){
      for(int i=1; i<n; i++)
	mat[akr(v[x], i)][2]++;
      break;
    }
  }

  
  if(k>0)mat=powMod(mat, k);
  
  LL ans;
  if(s==e)ans=mat[0][0];
  else ans=mat[0][1];

  printf("%d\n", (int)ans);
  return 0;
}