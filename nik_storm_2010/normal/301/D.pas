uses math;
var
    quest,pair:array[1..3,1..5000000] of longint; tree,pos,ans:array[1..5000000] of longint;
      kol,cur,n,m,i,j,c:longint;


procedure quicksortpair(l,r:longint);
var i,j,w,d:longint;
begin
  i:=l; j:=r; d:=pair[1,random(r-l+1)+l];
  while i<=j do
    begin
      while pair[1,i]<d do inc(i);
      while pair[1,j]>d do dec(j);
      if i<=j then
        begin
          w:=pair[1,i]; pair[1,i]:=pair[1,j]; pair[1,j]:=w;
          w:=pair[2,i]; pair[2,i]:=pair[2,j]; pair[2,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksortpair(i,r);
  if l<j then quicksortpair(l,j);
end;


procedure quicksortquest(l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=quest[1,random(r-l+1)+l];
  while i<=j do
    begin
      while quest[1,i]<d do inc(i);
      while quest[1,j]>d do dec(j);
      if i<=j then
        begin
          w:=quest[1,i]; quest[1,i]:=quest[1,j]; quest[1,j]:=w;
          w:=quest[2,i]; quest[2,i]:=quest[2,j]; quest[2,j]:=w;
          w:=quest[3,i]; quest[3,i]:=quest[3,j]; quest[3,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksortquest(i,r);
  if l<j then quicksortquest(l,j);
end;


procedure modify(i,l,r,x,d:longint);
var m:longint;
begin
  if (l=r) then tree[i]:=tree[i]+d else
    begin
      m:=(l+r) div 2;
      if x<=m then modify(i*2,l,m,x,d) else modify(i*2+1,m+1,r,x,d);
      tree[i]:=tree[i*2]+tree[i*2+1];
    end;
end;


function findsum(i,l,r,ql,qr:longint):longint;
var m,res:longint;
begin
  if (l=ql) and (r=qr) then findsum:=tree[i] else
    begin
      m:=(l+r) div 2; res:=0;
      if (ql<=m) then res:=res+findsum(i*2,l,m,ql,min(qr,m));
      if (m<qr) then res:=res+findsum(i*2+1,m+1,r,max(ql,m+1),qr);
      findsum:=res;
    end;
end;


begin

  readln(n,m); kol:=0;
  for i:=1 to n do begin read(c); pos[c]:=i; end;
  for i:=1 to n do
    begin
      j:=i;
      while j<=n do
        begin
          inc(kol); pair[1,kol]:=min(pos[i],pos[j]); pair[2,kol]:=max(pos[i],pos[j]);
          j:=j+i;
        end;
    end;
  for i:=1 to m do
    begin
      readln(quest[1,i],quest[2,i]); quest[3,i]:=i;
    end;
  randomize;
  quicksortpair(1,kol); quicksortquest(1,m);
  cur:=kol;
  for i:=m downto 1 do
    begin
      while (cur>0) and (pair[1,cur]>=quest[1,i]) do
        begin
          modify(1,1,n,pair[2,cur],1);
          dec(cur);
        end;
      ans[quest[3,i]]:=findsum(1,1,n,quest[1,i],quest[2,i]);
    end;
  for i:=1 to m do writeln(ans[i]);

end.