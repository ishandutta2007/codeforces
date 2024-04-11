import Control.Monad
import Data.List
import Data.Bits

f [aa,oo,xx] a b c d = ((a `oo` b) `aa` (c `xx` d)) `oo` ((b `aa` c) `xx` (a `oo` d))

g :: Int -> Int -> Int -> Int -> [Int]
g a b c d = map (\xs -> f xs a b c d) $ permutations [(.&.),(.|.),xor]

main = do
    [a,b,c,d] <- replicateM 4 $ fmap read getLine
    print $ g a b c d !! 5