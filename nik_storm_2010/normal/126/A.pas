var
  sum,x1,x2,t0,t1,t2,x,y,i,j:int64; ans,raz:extended;


function fun(i,j:extended):extended;
begin
  exit((t1*i+t2*j)/(i+j));
end;


procedure dichotomy(i:int64;var j:int64;var raz:extended);
var l,r,m:int64; c1,c2:extended;
begin
  if i=0 then l:=1 else l:=0; r:=x2;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if fun(i,m)>t0 then r:=m else l:=m;
  end;
  if (fun(i,l)>=t0) and (fun(i,r)>=t0) then
  begin
    c1:=abs(fun(i,l)-t0); c2:=abs(fun(i,r)-t0);
    if (c1>=c2)
    then begin j:=r; raz:=fun(i,r); end
    else begin j:=l; raz:=fun(i,l); end;
  end
    else
  begin
    if fun(i,l)>=t0 then begin j:=l; raz:=fun(i,l); end else
    if fun(i,r)>=t0 then begin j:=r; raz:=fun(i,r); end else j:=-1;
  end;

end;


begin

  readln(t1,t2,x1,x2,t0); ans:=1e18; i:=1;
  if (t2>=t0) then begin ans:=t2; sum:=x2; x:=0; y:=x2; end;
  while i<=x1 do
  begin
    dichotomy(i,j,raz);
    if (j<>-1) and ((raz<ans) or ((raz=ans) and (sum<i+j)))
    then
    begin
      ans:=raz; sum:=i+j;
      x:=i; y:=j;
    end;
    inc(i);
  end;
  writeln(x,' ',y);

end.