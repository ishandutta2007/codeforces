#include <string>
#include <iostream>
using namespace std;
string s;
int n,k;
int main(){
	cin>>n>>k;
	cin>>s;
	int cnt=0;
	if(k==2){
			 for(int i=0;i<n;i++)if(s[i]-'A'!=(i&1)){cnt++;s[i]='A'+(i&1);}
			 if(n-cnt<cnt){
			 			   cout<<n-cnt<<endl;
			 			   for(int i=0;i<n;i++)if(s[i]=='A')cout<<'B';else cout<<'A';
			}
			else {
				 cout<<cnt<<endl<<s<<endl;
			}
	}
	else {
		 for(int i=0;i<n-1;i++)
		 if(s[i]==s[i+1]){
		 				  i++;
		 				  cnt++;
		 				  for(int j=0;j<3;j++){
						  		  if(s[i-1]-'A'==j)continue;
						  		  if(i!=n-1&&s[i+1]-'A'==j)continue;
						  		  s[i]=char(j+'A');
						  		  break;
						}
		}
		cout<<cnt<<endl<<s<<endl;

	}
	//system("pause");
	return 0;
	
}