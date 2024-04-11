var
  ss:array[0..40000] of string; sam:array[1..10] of string; s:string;
  l,r,leng:array[1..10] of longint; ans,cnt,n,d,i,j:longint; sim:char;


procedure quicksort(l,r:longint);
var i,j:longint; d,w:string;
begin
  i:=l; j:=r; d:=ss[random(r-l+1)+l];
  while i<=j do
  begin
    while ss[i]<d do inc(i);
    while ss[j]>d do dec(j);
    if i<=j then
    begin
      w:=ss[i]; ss[i]:=ss[j]; ss[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


function check(s:string):boolean;
var i,j,k,ll:longint;
begin
  ll:=length(s); check:=true;
  for i:=1 to n do
  begin
    k:=0;
    for j:=1 to leng[i]-ll+1 do if copy(sam[i],j,ll)=s then inc(k);
    if not((l[i]<=k) and (k<=r[i])) then exit(false);
  end;
end;


begin

  readln(s); readln(n);
  for i:=1 to n do
  begin
    while true do
    begin
      read(sim); if sim=' ' then break;
      sam[i]:=sam[i]+sim;
    end;
    readln(l[i],r[i]); leng[i]:=length(sam[i]);
  end;
  d:=length(s);
  for i:=1 to d do for j:=i to d do
    if check(copy(s,i,j-i+1))=true then
    begin
      inc(cnt);
      ss[cnt]:=copy(s,i,j-i+1);
    end;
  randomize; quicksort(1,cnt);
  for i:=1 to cnt do if ss[i]<>ss[i-1] then inc(ans);
  writeln(ans);

end.