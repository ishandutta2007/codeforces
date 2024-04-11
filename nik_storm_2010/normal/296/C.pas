var
    a,b,c,d,l,r:array[0..100001] of int64; x,y,n,m,k,cur:int64; i:longint;


begin

  readln(n,m,k);
  for i:=1 to n do read(a[i]); readln;
  for i:=1 to m do readln(l[i],r[i],d[i]);
  fillchar(c,sizeof(c),0);
  for i:=1 to k do
    begin
      readln(x,y);
      c[x]:=c[x]+1; c[y+1]:=c[y+1]-1;
    end;
  fillchar(b,sizeof(b),0); cur:=0;
  for i:=1 to m do
    begin
      cur:=cur+c[i];
      b[l[i]]:=b[l[i]]+cur*d[i]; b[r[i]+1]:=b[r[i]+1]-cur*d[i];
    end;
  cur:=0;
  for i:=1 to n do
    begin
      cur:=cur+b[i]; write(a[i]+cur,' ');
    end;

end.