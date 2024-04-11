var stek : array[1..1000] of string; c1,c2,c3 : char;
     endofstek,leng,beg,n,i : longint; s,tek:string;


procedure WriteTekPath;
var i:longint;
 begin
  write('/');
   for i:=1 to endofstek do write(stek[i],'/');
  writeln;
 end;


procedure next(var tek:string);
 begin
  tek:='';
   if beg > leng then begin tek:='-'; exit; end;

  while (beg<=leng) and (s[beg]<>'/') do
   begin
    tek:=tek + s[beg];
    inc(beg);
   end;
  inc(beg);
 end;


begin

  readln(n);
   endofstek:=0;
  for i:=1 to n do
   begin
    read(c1,c2,c3);
     if c1 = 'p'
      then
       begin
        WriteTekPath;
        readln;
       end
      else
       begin
        readln(s);
         leng:=length(s);
        if s[1] = '/'
         then
          begin
           endofstek:=0;
           beg:=2;
          end
         else beg:=1;

        while true do
         begin
          next(tek);
           if tek = '-' then break;
          if tek = '..'
           then
            begin
             dec(endofstek);
            end
           else
            begin
             inc(endofstek);
             stek[endofstek]:=tek;
            end;
         end;
       end;
   end;

end.