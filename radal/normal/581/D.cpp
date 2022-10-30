#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
using namespace std; 
const int N=1e2;
set <ll> pos,neg;
pair <ll,ll> c[N];
char a[N][N];
int main(){
ll x1,y1,x2,y2,x3,y3;
cin >> x1 >> y1;
cin >> x2 >> y2;
cin >> x3 >> y3;
ll sum = x1*y1+x2*y2+x3*y3;
sum = sqrt(sum);
if (pow(sum,2) != x1*y1+x2*y2+x3*y3){
	cout << -1;
	return 0;
}
if (x1 < y1) swap(x1,y1);
if (x2 < y2) swap(x2,y2);
if (x3 < y3) swap(x3,y3);
if (x1 == x2){
	if (x1 == x3 && x1 == y1+y2+y3){
		rep (i,0,x1){
			rep(j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep (i,0,x2){
			rep(j,y1,y1+y2){
				a[i][j] = 'B';
			}
		}
		rep (i,0,x1){
			rep(j,y1+y2,y1+y2+y3){
				a[i][j] = 'C';
			}
		}
		cout << x1 << endl;
		rep (i,0,x1){
			rep(j,0,y1+y2+y3){
				cout << a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	if (x1 == y3 && x1 == x3+y2+y1){
		rep (i,0,x1){
			rep(j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep (i,0,x2){
			rep(j,y1,y1+y2){
				a[i][j] = 'B';
			}
		}
		rep (i,0,y3){
			rep(j,y1+y2,y1+y2+x3){
				a[i][j] = 'C';
			}
		}
		cout << x1 <<endl;
		rep (i,0,x1){
			rep(j,0,y1+y2+x3){
				cout << a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	if (y1+y2 == y3){
		rep(i,0,x1){
			rep(j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep(i,0,x1){
			rep(j,y1,y1+y2){
				a[i][j] = 'B';
			}
		}
		rep(i,x1,x1+x3){
			rep(j,0,y3){
				a[i][j] = 'C';
			}
		}
		cout << y3 << endl;
		rep (i,0,x1+x3){
			rep(j,0,y3){
				cout << a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}
	if (y1+y2 == x3){
		rep(i,0,x1){
			rep(j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep(i,0,x1){
			rep(j,y1,y1+y2){
				a[i][j] = 'B';
			}
		}
		rep(i,x1,x1+y3){
			rep(j,0,x3){
				a[i][j] = 'C';
			}
		}
		cout << x3 <<endl;
		rep (i,0,x1+y3){
			rep(j,0,x3){
				cout << a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}	
}
if (y1 == y2){
	if (y2 == y3 || y2 == x3){
		if (y2 == x3) swap(y3,x3);
		if (y1 == x1+x2+x3){	
			rep (i,0,x1){
				rep (j,0,y1){
					a[i][j] = 'A';
				}
			}
			rep (i,x1,x2+x1){
				rep (j,0,y1){
					a[i][j] = 'B';
				}
			}
			rep (i,x1+x2,x2+x3+x1){
				rep (j,0,y1){
					a[i][j] = 'C';
				}
			}
			cout << y1 << endl;
			rep(i,0,x1+x2+x3){
				rep(j,0,y1){
					cout << a[i][j];
				}
				cout << endl;
			}
			return 0;
		}
	}
	if (y3 == x1+x2 || x3 == x1+x2){
		if (y3 == x1+x2) swap(y3,x3);
		rep(i,0,x1){
			rep(j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep (i,x1,x2+x1){
			rep (j,0,y1){
				a[i][j] = 'B';
			}
		}
		rep (i,0,x3){
			rep (j,y1,y3+y1){
			a[i][j] = 'C';
			}
		}
		cout << x3 << endl;
		rep (i,0,x3){
			rep (j,0,y3+y1){
				cout<<a[i][j];
			}
			cout<<endl;
		}
		return 0;
	}	
}
if (x1 == x3 || x1 == y3){
	if (x1 == y3) swap(x3,y3);
	if (y1+y3 == y2 || y1+y3 == x2){	
		if (y1+y3 == x2) swap(x2,y2);
		rep (i,0,x1){
			rep (j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep (i,0,x1){
			rep (j,y1,y1+y3){
				a[i][j] = 'C';
			}
		}
		rep (i,x1,x2+x1){
			rep (j,0,y2){
				a[i][j] = 'B';
			}
		}
		cout << y2 <<endl;
		rep (i,0,x1+x2){
			rep (j,0,y2){
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;			
	}
}
if (x3 + x2 == x1 || x3 + x2 == y1){
	if (y2 == y3){
		if (x3+x2 == y1) swap (x1,y1);
		rep (i,0,x1){
			rep (j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep (i,0,x2){
			rep (j,y1,y1+y2){
				a[i][j] = 'B';
			}
		}
		rep (i,x2,x2+x3){
			rep (j,y1,y1+y2){
				a[i][j] = 'C';
			}
		}
		cout << x1 << endl;
		rep (i,0,x1){
			rep (j,0,y1+y2){
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}
}
if (y3 + y2 == x1 || y3 + y2 == y1){
	if (x2 == x3){
		if (y3+y2 == x1) swap (x1,y1);
		rep (i,0,x1){
			rep (j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep (i,x1,x1+x2){
			rep (j,0,y2){
				a[i][j] = 'B';
			}
		}
		rep (i,x1,x1+x3){
			rep (j,y2,y3+y2){
				a[i][j] = 'C';
			}
		}
		cout << y1 << endl;
		rep (i,0,x1+x3){
			rep (j,0,y1){
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}
}
if (y1 == y3){
	if (y1 == y2 || y1 == x2){
		if (x2 == y3) swap(y2,x2);
		if (y1 == x2+x1+x3){	
			rep (i,0,x1){
				rep (j,0,y1){
					a[i][j] = 'A';
				}
			}
			rep (i,x1,x2+x1){
				rep (j,0,y1){
					a[i][j] = 'B';
				}
			}
			rep (i,x1+x2,x2+x3+x1){
				rep (j,0,y1){
					a[i][j] = 'C';
				}
			}
			cout << y1 << endl;
			rep(i,0,x1+x2+x3){
				rep(j,0,y1){
					cout << a[i][j];
				}
				cout << endl;
			}
			return 0;
		}
	}
	if (y2 == x1+x3 || x2 == x1+x3){
		if (y2 == x1+x3) swap(y2,x2);
		if (y1 == y3){
			rep(i,0,x1){
				rep(j,0,y1){
					a[i][j] = 'A';
				}
			}
			rep (i,x1,x3+x1){
				rep (j,0,y1){
					a[i][j] = 'C';
				}
			}
			rep (i,0,x2){
				rep (j,y1,y2+y1){
					a[i][j] = 'B';
				}
			}
			cout << y2+y1 << endl;
			rep (i,0,x2){
				rep (j,0,y2+y1){
					cout<<a[i][j];
				}
				cout<<endl;
			}
			return 0;
		}
	}	
}
if (x1+y3 == x2 || x1+y3 == y2){
	if (x1+y3 == y2) swap(y2,x2);
	if (y1 == x3){
		rep(i,0,x2){
			rep (j,0,y2){
				a[i][j] = 'B';
			}
		}
		rep(i,0,x1){
			rep (j,y2,y1+y2){
				a[i][j] = 'A';
			}
		}
		rep(i,x1,x2){
			rep (j,y2,y2+y1){
				a[i][j] = 'C';
			}
		}
		cout << x2 <<endl;
		rep(i,0,x2){
			rep (j,0,y1+y2){
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}
}
if (y2 + x3 == x1 || y2 + x3 == y1){
	if (y2 + x3 == y1) swap (x1,y1);
	if (x2 == y3){
		rep(i,0,x1){
			rep (j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep(i,0,y2){
			rep (j,y1,x2+y1){
				a[i][j] = 'B';
			}
		}
		rep(i,y2,x3+y2){
			rep (j,y1,x2+y1){
				a[i][j] = 'C';
			}
		}
		cout << x1 <<endl;
		rep(i,0,x1){
			rep (j,0,x2+y1){
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}
}
if (x1 + y2 == x3 || x1 + y2 == y3){
	if (x1+y2 == y3) swap(x3,y3);
	if (y1 == x2){
		rep(i,0,x3){
			rep (j,0,y3){
				a[i][j] = 'C';
			}
		}
		rep(i,0,x1){
			rep (j,y3,x2+y3){
				a[i][j] = 'A';
			}
		}
		rep(i,x1,x3){
			rep (j,y3,x2+y3){
				a[i][j] = 'B';
			}
		}
		cout << x3 << endl;
		rep(i,0,x3){
			rep (j,0,x2+y3){
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}
}
if (x1 == x2 + y3 || x2 + y3 == y1){
	if (x2+y3 == y1) swap(y1,x1);
	if (y2 == x3){
		rep(i,0,x1){
			rep (j,0,y1){
				a[i][j] = 'A';
			}
		}
		rep(i,0,x2){
			rep (j,y1,y2+y1){
				a[i][j] = 'B';
			}
		}
		rep(i,x2,x1){
			rep (j,y1,y2+y1){
				a[i][j] = 'C';
			}
		}
		cout << x1 << endl;
		rep(i,0,x1){
			rep (j,0,y2+y1){
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}
}
cout << -1;	

}