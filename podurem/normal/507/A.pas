type
	Tmas1=array[1..100] of longint;
	Tmas=array[1..100] of Tmas1;
	
var
	a:Tmas;
	n,k,i,o,sum:longint;
	b:Tmas1;
	
procedure QSort(var v:Tmas; l,r:longint);
var 
	i,j,q:longint;
	w:Tmas1;
begin
  i:=l; 
  j:=r;
  q:=v[l+random(r-l+1)][1];
  repeat
    while (v[i][1]<q) do inc(i);
    while (q<v[j][1]) do dec(j);
    if (i<=j) then
    begin
      w:=v[i]; 
      v[i]:=v[j]; 
      v[j]:=w;
      inc(i); 
      dec(j);
    end;
  until (i>j);
  if (l<j) then QSort(v,l,j);
  if (i<r) then QSort(v,i,r);
end;
	
BEGIN
readln(n,k);
for i:=1 to n do
	begin
		read(a[i][1]);
		a[i][2]:=i;
	end;
QSort(a,1,n);
sum:=0;
o:=0;
repeat
	inc(o);
	inc(sum,a[o][1]);
	b[o]:=a[o][2];
until (sum+a[o+1][1]>k) or (o=n);
if sum>k then writeln(0) else begin writeln(o);
for i:=1 to o do
	write(b[i],' '); end;
END.