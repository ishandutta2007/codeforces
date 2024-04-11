const
  lim=100000;
type
  event=record l,p:extended; end;
var
  a:array[1..lim] of event;
  n,i,j:longint;
  ans,sum:extended;

function less(a,b:event):boolean;
begin
  if (a.l*a.p*(1-b.p)<b.l*b.p*(1-a.p)) then less:=true else less:=false;
end;

procedure sort(l,r:longint);
var
  i,j:longint;
  d,w:event;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l];
  repeat
    while less(d,a[i]) do inc(i);
    while less(a[j],d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i); dec(j);
    end;
  until (i>j);
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

begin
  readln(n);
  for i:=1 to n do begin readln(a[i].l,a[i].p); a[i].p:=a[i].p/100; end;
  randomize;
  sort(1,n);
  for i:=1 to n do
  begin
    ans:=ans+a[i].l+sum*(1-a[i].p);
    sum:=sum+a[i].l*a[i].p;
  end;
  writeln(ans:0:9);
end.