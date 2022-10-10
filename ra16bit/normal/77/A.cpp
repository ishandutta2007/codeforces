#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const string c[7]={"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"};
int n,i,j,k,e,a[3],b[3],cc[7],z[3],cr,r=2000000200;
string s,t,l;
bool g[7][7];
void rec(int l) {
  int i,j;
  if (l==7) {
    for (i=0; i<3; i++) if (b[i]==0) return; else z[i]=a[i]/b[i];
    sort(z,z+3);
    if (z[2]-z[0]>r) return;
    for (e=i=0; i<7; i++) for (j=0; j<7; j++) if (g[i][j] && cc[i]==cc[j]) e++;
    if (z[2]-z[0]<r || (z[2]-z[0]==r && e>cr)) { r=z[2]-z[0]; cr=e; }
    return;
  }
  for (i=0; i<3; i++) {
    b[i]++; cc[l]=i; rec(l+1); b[i]--;
  }
}
int main() {
  cin>>n;
  for (i=0; i<n; i++) {
    cin>>s>>l>>t;
    for (j=0; j<7; j++) if (s==c[j]) break;
    for (k=0; k<7; k++) if (t==c[k]) break;
    g[j][k]=true;
    
  }
  for (i=0; i<3; i++) cin>>a[i];
  rec(0);
  cout<<r<<' '<<cr<<'\n';
  return 0;
}