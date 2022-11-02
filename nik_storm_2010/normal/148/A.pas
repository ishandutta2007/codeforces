var
   used:array[1..100000] of boolean;
    k,l,m,n,d,i,answer:longint;

begin
 readln(k); readln(l); readln(m); readln(n); readln(d);
  i:=k;
   while i<=d do begin used[i]:=true; i:=i+k; end;
  i:=l;
   while i<=d do begin used[i]:=true; i:=i+l; end;
  i:=m;
   while i<=d do begin used[i]:=true; i:=i+m; end;
  i:=n;
   while i<=d do begin used[i]:=true; i:=i+n; end;
  answer:=0;
   for i:=1 to d do
    if used[i]=true then inc(answer);
  writeln(answer);
end.