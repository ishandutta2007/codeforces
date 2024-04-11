type
  edges=record
    frm,nxt:longint;
  end;
const
  ll=1000000;
  big=1000000000;
var
  ee:array[1..ll] of edges;
  start,ans,step:array[1..ll] of longint;
  q:array[1..4*ll] of longint;
  used:array[1..ll] of boolean;
  bg,fn,n,m,i,x,y,z,w,s,t:longint;

procedure addstr(x:longint);
begin
  dec(bg);
  q[bg]:=x;
end;

procedure addend(x:longint);
begin
  q[fn]:=x;
  inc(fn);
end;

begin
  bg:=2*ll; fn:=2*ll;
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y);
    ee[i].frm:=x;
    ee[i].nxt:=start[y];
    start[y]:=i;
    inc(step[x]);
    //addend(y);
  end;
  readln(s,t);
  for i:=1 to n do ans[i]:=big;
  ans[t]:=0;
  addend(t);
  while (bg<>fn) do
  begin
    z:=q[bg];
    inc(bg);
    if (used[z]) then continue;
    i:=start[z];
    while (i<>0) do
    begin
      w:=ee[i].frm;
      dec(step[w]);
      if (step[w]=0) then
      begin
        if (ans[w]>ans[z]) then
        begin
          ans[w]:=ans[z];
          addstr(w);
        end;
      end
        else
      begin
        if (ans[w]>ans[z]+1) then
        begin
          ans[w]:=ans[z]+1;
          addend(w);
        end;
      end;
      i:=ee[i].nxt;
    end;
    used[z]:=true;
  end;
  if (ans[s]=big) then writeln(-1) else writeln(ans[s]);
end.