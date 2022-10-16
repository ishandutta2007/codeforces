#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 300010
#define N 100000
// #define cout out
// #define cin in
lli inf = pow(10,18);
lli modulo = inf+ 7;
double eps = 1e-12;
ifstream in;
ofstream out;
pair<lli,char> all[MAX];
lli s = 0;
lli n;
vector<lli> gr;
void deal(){
	lli lb = -1, lr = -1;
	fori(n){
		if(all[i].ss=='R'){
			if(lr!=-1)
				s+=all[i].ff - lr;
			lr = all[i].ff;
		}
		else if(all[i].ss=='B'){
			if(lb!=-1)
				s+=all[i].ff - lb;
			lb = all[i].ff;
		}
		else{
			if(lr!=-1)
				s+=all[i].ff-lr;
			if(lb!=-1)
				s+=all[i].ff-lb;
			break;
		}
	}
	if(!gr.size())
		return;
	lb = -1, lr = -1;
	for(int i=n-1; i>-1; i--){
		if(all[i].ss=='R'){
			if(lr!=-1)
				s+=lr-all[i].ff ;
			lr = all[i].ff;
		}
		else if(all[i].ss=='B'){
			if(lb!=-1)
				s+=lb-all[i].ff;
			lb = all[i].ff;
		}
		else{
			if(lr!=-1)
				s+=lr-all[i].ff ;
			if(lb!=-1)
				s+=lb-all[i].ff ;
			break;
		}
	}
}
int main(){
	cin>>n;
	fori(n){
		cin>>all[i].ff>>all[i].ss;
		if(all[i].ss=='G')
			gr.push_back(i);
	}
	fork((int)gr.size()-1){
		lli i = gr[k];
				lli ind = i+1;
				deque<lli> blue,red;
				while(all[ind].ss!='G'){
					if(all[ind].ss=='B')
						blue.push_back(all[ind].ff);
					else
						red.push_back(all[ind].ff);
					++ind;
				}
					blue.push_front(all[i].ff);
					red.push_front(all[i].ff);
					blue.push_back(all[ind].ff);
					red.push_back(all[ind].ff);
				if(!blue.size() || !red.size()){
					lli big = 0;
					for(lli j=1; j<blue.size() ; j++)
						if(blue[j]-blue[j-1]>big)
							big = blue[j]-blue[j-1];
					s-=big;
					big = 0;
					for(lli j=1; j<red.size() ; j++)
						if(red[j]-red[j-1]>big)
							big = red[j]-red[j-1];
					s-=big;
					s+=all[ind].ff-all[i].ff;
				}
				else{
					lli big1 = 0;
					for(lli j=1; j<blue.size() ; j++)
						if(blue[j]-blue[j-1]>big1)
							big1 = blue[j]-blue[j-1];
					lli big2 = 0;
					for(lli j=1; j<red.size() ; j++)
						if(red[j]-red[j-1]>big2)
							big2 = red[j]-red[j-1];
					lli c1 = 3*(all[ind].ff - all[i].ff)-big1-big2;
					lli c2 = 2*(all[ind].ff - all[i].ff);
		//			cout<<big1<<" "<<big2<<" "<<c1<<" "<<c2<<endl;
					s+=min(c1,c2);
				}
	}
	deal();
	cout<<s;
}