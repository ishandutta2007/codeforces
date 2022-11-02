var
    a,b:array[1..10000] of longint; l,r,p:array[0..500] of longint;
      ans,rr,ll,n,m,i,j,x,y,q:longint;


function findset(i:longint):longint;
begin
  if p[i]<>i then p[i]:=findset(p[i]);
  findset:=p[i];
end;


procedure union(i,j:longint);
begin
  i:=findset(i); j:=findset(j);
  if random(2)=0 then p[i]:=j else p[j]:=i;
end;


begin

  readln(n,m); for i:=1 to m do readln(a[i],b[i]);
  for i:=1 to n do p[i]:=i;
  for i:=1 to m do
    begin
      x:=findset(a[i]); y:=findset(b[i]);
      if x<>y then
        begin
          inc(l[0]); l[l[0]]:=i;
          union(x,y);
        end;
    end;
  for i:=1 to n do p[i]:=i;
  for i:=m downto 1 do
    begin
      x:=findset(a[i]); y:=findset(b[i]);
      if x<>y then
        begin
          inc(r[0]); r[r[0]]:=i;
          union(x,y);
        end;
    end;
  readln(q);
  for i:=1 to q do
    begin
      readln(ll,rr); ans:=n;
      for j:=1 to n do p[j]:=j;
      for j:=1 to l[0] do
        begin
          if l[j]>=ll then break;
          x:=findset(a[l[j]]); y:=findset(b[l[j]]);
          if x<>y then begin union(x,y); dec(ans); end;
        end;
      for j:=1 to r[0] do
        begin
          if r[j]<=rr then break;
          x:=findset(a[r[j]]); y:=findset(b[r[j]]);
          if x<>y then begin union(x,y); dec(ans); end;
        end;
      writeln(ans);
    end;

end.