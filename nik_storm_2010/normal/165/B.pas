var
   l,r,n,k,ll,mid,tek : int64;



procedure ans(c:int64; var u:int64);
var i:int64;
 begin
  u:=c; i:=k;
   while trunc(c / i) > 0 do
    begin
     u:=u + trunc(c / i);
     i:=i*k;
    end;
 end;


begin

  readln(n,k);

  l:=1; r:=1000000000;
   while r-l>1 do
    begin
     mid:=(r+l) div 2;
      ans(mid,tek);
     if tek > n then r:=mid else l:=mid;
    end;

  ans(l,ll);
   if ll>=n
  then writeln(l) else writeln(r);

end.