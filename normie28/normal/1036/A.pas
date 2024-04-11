var n,k:int64;
begin
read(n,k);
if (k mod n)=0 then write(k div n) else write((k div n)+1);
end.