#include<bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int W[N], H[N];
long long preW[N], postW[N];
int preH[N], postH[N];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin>>n;
  for (int i=1; i<=n; ++i) cin>>W[i]>>H[i];
  for (int i=1; i<=n; ++i) {
    preW[i]=preW[i-1]+W[i];
    preH[i]=max(preH[i-1],H[i]);
  }
  for (int i=n; i>=1; --i) {
    postW[i]=postW[i+1]+W[i];
    postH[i]=max(postH[i+1], H[i]);
  }
 
  for (int i=1; i<=n; ++i) {
    long long w=preW[i-1]+postW[i+1];
    int h = max(preH[i-1], postH[i+1]);
    long long ans=w*h;
	cout<<ans<<' ';
}
}