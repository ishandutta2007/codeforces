#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll l;
string digits;
string addition(ll loc){
	//if (digits[loc]==0){
		//return "9999999999";
	//}
	//ll dig[100005];
	//memset(dig,0,sizeof(dig));
	//if (loc==l-loc-2){
		//for (int i = 0; i <=loc; i++){
			//dig[i+1]=digits[i]+digits[l-loc-1+i];
		//}
		//for (int i = loc+1; i >=1; i--){
			//if (dig[i]>9){
				//int y=dig[i];
				//y= y/10;
				//dig[i]%=10;
				//dig[i-1]+=y;
			//}
		//}
		//string s;
		//if (dig[0]!=0){
			////s+="a";
			//s+= dig[0]+'0';
			////dig[0]+'0';
		//}
		//for (int i = 1; i <=loc+1; i++){
			
			//s+=dig[i]+'0';
			////s[i-1]=dig[i]+'0';
			
		//}
		//return s;
	//} else{
		string a,b;
		a="0";
		for (int i = 0; i <=loc; i++){
			a+=digits[i];
		}
		for (int i = loc+1; i <l; i++){
			b+=digits[i];
		}
		ll A=a.size();
		ll B=b.size();
		if (A<B){
			swap(A,B);
			swap(a,b);
		}
		
		for (int i = 0; i <B; i++){
			a[A-i-1]+=b[B-i-1]-'0';
			if (a[A-i-1]>'9'){
				ll v=a[A-i-1];
				v-='0';
				v/=10;
				a[A-i-2]+=v;
				a[A-i-1]-='0';
				a[A-i-1]%=10;
				a[A-i-1]+='0';
				
				
			}
		}
		for (int i = 0; i <A; i++){
			//a[A-i-1]+=b[B-i-1]-'0';
			if (a[A-i-1]>'9'){
				ll v=a[A-i-1];
				v-='0';
				v/=10;
				a[A-i-2]+=v;
				a[A-i-1]-='0';
				a[A-i-1]%=10;
				a[A-i-1]+='0';
				
				
			}
		}
		
		string s;
		if (a[0]!='0'){
			//s+="a";
			s=a;
			return s;
			//dig[0]+'0';
		} else{
			for (int i = 1; i <A; i++){
				
				s+=a[i];
				//s[i-1]=dig[i]+'0';
				
			}
			return s;	
		}
		
	//}
	
	
}
int main (){

	cin >> l>>digits;
	//for (int i = 0; i <l; i++){
		//char o;
		//cin >> o;
		//digits[i]= o-'0';
		////cin >> digits[i];
	//}
	queue<ll> q;
	
	if (l&1){
		ll mid= l/2;
		//mid++;
	
		q.push(mid-1);
		q.push(mid);
		
		
	} else{
		ll mid=l/2;
		//q.push(mid);
		q.push(mid-1);
		q.push(mid-1);
		//if (digits[mid]!=0){
			//string h=addition(mid-1);
			//cout << h << endl;
			//return 0;
		//}
		//q.push(mid-1);
		//q.push(mid);
	}
	
	while (true){
		ll can1=q.front();
		q.pop();
		ll can2=q.front();
		q.pop();
		
		if (digits[can1+1]=='0' and digits[can2+1]=='0'){
			q.push(can1-1);
			q.push(can2+1);
			continue;
		}
		if (digits[can1+1]=='0'){
			string h=addition(can2);
			cout << h << endl;
			return 0;
		}
		if (digits[can2+1]=='0'){
			
			string h=addition(can1);
			
			cout << h << endl;
			return 0;
		}
		
		string add1= addition(can1);
		string add2=addition(can2);
		string al;
		vector<string> v;
		v.push_back(add1);
		v.push_back(add2);
		sort(v.begin(),v.end());
		//cout << add1 << " "<<add2 << endl;
		if (add1.length()!=add2.length()){
			if (add1.length()<add2.length()){
				al=add1;
			} else{
				al=add2;
			}
		} else{
			al=v[0];
			//if (add1>add2){
				//al=add1;
			//} else{
				//al=add2;
			//}
		}
		cout << al << endl;
		return 0;
	}
}